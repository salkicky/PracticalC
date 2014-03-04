#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "words_dict.h"

typedef struct _WORD_INFO_T {
	char *word;                             // 単語記憶領域へのポインタ
	int count;                              // 単語の登録回数
    struct _WORD_INFO_T *bp;                // 前のリストへのポインタ
	struct _WORD_INFO_T *np;                // 次のリストへのポインタ
} WORD_INFO_T;

typedef struct {
    WORD_INFO_T *head;                      // リスト先頭へのポインタ
    WORD_INFO_T *curr;                      // リスト作業領域
} DICT_T;

WORD_INFO_T *_alloc_wordinfo(char *word, int word_len);        // 単語管理領域を確保する
void _free_wordinfo(WORD_INFO_T *winfo);                        // 単語管理領域を解放する

/*********************************************************
 * word_dict_create_context
 * 
 * 実行用のコンテキストを生成する。
 * 利用終了後は必ず word_dict_destroy_context()で解放すること。
 *
 * @return 実行用コンテキストへのポインタ
 *********************************************************/
void *word_dict_create_context(void)
{
    DICT_T *dict;

    dict = (DICT_T *)malloc(sizeof(DICT_T));
    dict->head = NULL;
    dict->curr = NULL;

    return (void *)dict;
}

/*********************************************************
 * word_dict_destroy_context
 *
 * 確保した実行用コンテキストを解放する。
 *
 * @param [in]      *context 実行用コンテキスト
 *********************************************************/
void word_dict_destroy_context(void *context)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *next;
    
    // 単語リストの解放
    dict->curr = dict->head;

    while (dict->curr != NULL) {
        printf("-----\n");
        printf("  curr->word = %s\n", dict->curr->word);
        printf("  curr->count = %d\n", dict->curr->count);

        next = dict->curr->np;
        _free_wordinfo(dict->curr);
        dict->curr = next;
    }

    // 実行用コンテキストの解放
    free(context);
}

/*********************************************************
 * word_dict_add
 *
 * 単語を登録する。
 * 既に登録済みの単語の場合は、カウンタを+1する。
 *
 * @param [in]      *context    実行用コンテキスト
 * @param [in]      *word       単語文字列
 * @param [in]      word_len    登録する単語の文字数
 *********************************************************/
void word_dict_add(void *context, char *word, int word_len)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *winfo;

    if (word == NULL) {
        // 文字列が未セットなら何もしない
        return;
    }

    //if (*word = '\0') {
    //    // 文字列がヌルでも何もしない
    //}
    
    //// wordを探す
    //if (_serch(dictp, wordp) == FALSE) {
    //}

    // 無ければ登録
    
    // 渡された単語の管理領域を確保
    winfo = _alloc_wordinfo(word, word_len);

    // リストの後ろに連結する
    winfo->bp = dict->curr;
    if (dict->curr != NULL) {
        (dict->curr)->np = winfo;
    } else {
        dict->head = winfo;
    }
    dict->curr = winfo;
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
void word_dict_get_a_word(void *context, char **wordp, int *counter)
{
    DICT_T *dict = (DICT_T *)context;

    if (dict->curr != NULL) {
        *wordp = dict->curr->word;
        *counter = dict->curr->count;
    }
}

//=================================================================

// 指定した単語をサーチする
WORD_INFO_T *_search_from_dict(char *word)
{

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
