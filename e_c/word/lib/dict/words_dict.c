#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "words_dict.h"

typedef int _BOOL;
#define TRUE  1
#define FALSE 0

struct word_info_tag {
	char *word;
	int count;
	struct word_info_tag *next;
    struct word_info_tag *pre;
};

struct dict_tag {
    struct word_info_tag *head;
    struct word_info_tag *curr;
};

struct word_info_tag *_create_wordinfo(char *word, int word_len);
void _free_wordinfo(struct word_info_tag *winfo);

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
    struct dict_tag *dict;

    dict = (struct dict_tag *)malloc(sizeof(struct dict_tag));
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
    struct dict_tag *dict = (struct dict_tag *)context;
    struct word_info_tag *next;
    
    // 単語リストの解放
    dict->curr = dict->head;

    while (dict->curr != NULL) {
        printf("-----\n");
        printf("  curr->word = %s\n", dict->curr->word);
        printf("  curr->count = %d\n", dict->curr->count);

        next = dict->curr->next;
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
    struct dict_tag *dict = (struct dict_tag *)context;
    struct word_info_tag *winfo;

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
    
    // 渡された単語の記憶領域を生成
    winfo = _create_wordinfo(word, word_len);

    // リストの後ろに連結する
    winfo->pre = dict->curr;
    if (dict->curr != NULL) {
        (dict->curr)->next = winfo;
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
    struct dict_tag *dict = (struct dict_tag *)context;

    if (dict->curr != NULL) {
        *wordp = dict->curr->word;
        *counter = dict->curr->count;
    }
}

//=================================================================

// 単語の記憶領域を生成する
struct word_info_tag *_create_wordinfo(char *word, int word_len)
{
    struct word_info_tag *wp;

    wp = (struct word_info_tag *)malloc(sizeof(struct word_info_tag));
    wp->word = (char *)malloc(word_len+1);
    
    memcpy(wp->word, word, word_len);
    wp->word[word_len] = '\0';

    wp->count = 0;
    wp->next = NULL;
    wp->pre = NULL;

    return wp;
}

// 単語の記憶領域を解放する
void _free_wordinfo(struct word_info_tag *winfo)
{
    free((void *)winfo->word);
    free((void *)winfo);
}
