#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

/*********************************************************
 * word_dict_add
 *
 * 単語を登録する。
 * 既に登録済みの単語の場合は、カウンタを+1する。
 *
 * @param [in]      *word   単語文字列
 *********************************************************/
void word_dict_add(void *context, char *word, int word_len);

/*********************************************************
 * word_dict_create_context
 *
 *
 * @return 
 *********************************************************/
void *word_dict_create_context(void);

/*********************************************************
 * word_dict_destroy_context
 *
 *
 * @return 
 *********************************************************/
void word_dict_destroy_context(void *context);


void word_dict_get_a_word(void *context, char **wordp, int *counter);


#endif //_WORDS_DICT_H_
