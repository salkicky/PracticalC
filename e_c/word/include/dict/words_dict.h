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
void word_dict_add(char *word);


/*********************************************************
 * word_dict_get_context
 *
 *
 * @return 
 *********************************************************/
void *word_dict_get_context(void);



void word_dict_get_a_wordinfo(void *contextp, char *wordp, int *counter);







#endif //_WORDS_DICT_H_
