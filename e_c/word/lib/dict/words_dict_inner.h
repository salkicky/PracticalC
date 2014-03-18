#ifndef _INNER_WORDS_DICT_H_
#define _INNER_WORDS_DICT_H_

struct _WORD_INFO_T {
	char *word;                             // 単語記憶領域へのポインタ
	int count;                              // 単語の登録回数
    struct _WORD_INFO_T *bp;                // 前のリストへのポインタ
	struct _WORD_INFO_T *np;                // 次のリストへのポインタ
};
typedef struct _WORD_INFO_T WORD_INFO_T;

struct DictionaryContext_tag {
    WORD_INFO_T *head;                      // リスト先頭へのポインタ
    WORD_INFO_T *curr;                      // リスト作業領域
};
//typedef struct DictionaryContext_tag DICT_T;

#endif // _INNER_WORDS_DICT_H_
