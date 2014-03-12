#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "words_dict.h"
#include "inner_words_dict.h"

#define B_TRUE  1
#define B_FALSE 0

typedef int _BOOL;


// -----------------------------------------
// プロトタイプ宣言
// -----------------------------------------
_BOOL _search_from_dict(DICT_T *dict, char *word, WORD_INFO_T **match);
WORD_INFO_T *_alloc_wordinfo(char *word, int word_len);         // 単語管理領域を確保する
void _free_wordinfo(WORD_INFO_T *winfo);                        // 単語管理領域を解放する

/*********************************************************
 * word_dict_create_context
 * 
 * 実行用のコンテキストを生成する。
 * 利用終了後は必ず word_dict_destroy_context()で解放すること。
 *
 * @param [out] 実行用コンテキストへの pointer to pointer
 * @return DICT_RET_OK  正常終了
 * @return DICT_RET_NG  異常終了
 *********************************************************/
int word_dict_create_context(struct DictionaryContext_tag **contextp)
{
    DICT_T *dict;

    dict = (DICT_T *)malloc(sizeof(DICT_T));
    if (dict == NULL) {
        // メモリ確保失敗
        return DICT_RET_NG;
    }

    dict->head = NULL;
    dict->curr = NULL;

    *contextp = dict;

    return DICT_RET_OK;
}

/*********************************************************
 * word_dict_destroy_context
 *
 * 確保した実行用コンテキストを解放する。
 *
 * @param [in]      *context 実行用コンテキスト
 *********************************************************/
void word_dict_destroy_context(struct DictionaryContext_tag *context)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *next;
    
    // 単語リストの解放
    dict->curr = dict->head;

    while (dict->curr != NULL) {
        next = dict->curr->np;
        _free_wordinfo(dict->curr);
        dict->curr = next;
    }

    // 実行用コンテキストの解放
    free(context);
}

/*********************************************************
 * word_dict_register
 *
 * 単語を登録する。
 * 既に登録済みの単語の場合は、カウンタを+1する。
 *
 * @param [in]      *context    実行用コンテキスト
 * @param [in]      *word       単語文字列
 * @param [in]      word_len    登録する単語の文字数
 *********************************************************/
void word_dict_register(struct DictionaryContext_tag *context, char *word, int word_len)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *match;
    WORD_INFO_T *winfo;
    _BOOL    ret; 

    if (word == NULL) {
        // 文字列が未セットなら何もしない
        return;
    }

    if (dict->head != NULL) {
        // 初回でなければ
        ret = _search_from_dict(dict, word, &match);
        if (ret == B_TRUE) {
            // 登録済みならカウント
            match->count++;
        } else {
            // 未登録なら単語を登録

            // 渡された単語の管理領域を確保
            winfo = _alloc_wordinfo(word, word_len);

            // リストの後ろに連結する
            winfo->bp = dict->curr;
            (dict->curr)->np = winfo;
            dict->curr = winfo;
        }
    } else {
        // 初回なら

        // 渡された単語の管理領域を確保
        winfo = _alloc_wordinfo(word, word_len);

        // リストの後ろに連結する
        dict->head = winfo;
        dict->curr = winfo;
    }
}

/*********************************************************
 * word_dict_get_a_word
 *
 * 単語を一つ取り出す
 *
 * @param [in]      *context    実行用コンテキスト
 * @param [out]     *word       単語文字列
 * @param [out]     counter     登録した回数
 *********************************************************/
void word_dict_get_a_word(struct DictionaryContext_tag *context, char **wordp, int *counter)
{
    DICT_T *dict = (DICT_T *)context;

    *wordp = NULL;
    *counter = 0;

    if (dict->curr != NULL) {
        *wordp = dict->curr->word;
        *counter = dict->curr->count;
    }
}

//=================================================================

// 指定した単語をサーチする
_BOOL _search_from_dict(DICT_T *dict, char *word, WORD_INFO_T **match)
{
    dict->curr = dict->head;

    while (dict->curr != NULL) {

        if (strcmp(word, dict->curr->word) == 0) {
            // 文字列が一致したら
            *match = dict->curr;
            break;
        }

        if (dict->curr->np == NULL) {
            return B_FALSE;
        }
        dict->curr = dict->curr->np;
    }

    return B_TRUE;
}

// 単語の管理領域を確保する
WORD_INFO_T *_alloc_wordinfo(char *word, int word_len)
{
    WORD_INFO_T *wp;

    // 単語の管理領域を確保
    wp = (WORD_INFO_T *)malloc(sizeof(WORD_INFO_T));

    // 管理する単語の大きさに合わせて領域確保
    wp->word = (char *)malloc(word_len+1);

    // 単語の文字数分を新たに割り当てた領域へコピーし、終端を入れる
    memcpy(wp->word, word, word_len);
    wp->word[word_len] = '\0';

    // その他の領域を初期化
    wp->count = 1;
    wp->np = NULL;
    wp->bp = NULL;

    return wp;
}

// 単語の管理領域を解放する
void _free_wordinfo(WORD_INFO_T *winfo)
{
    free((void *)winfo->word);
    free((void *)winfo);
}
