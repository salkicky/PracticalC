#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

/*********************************************************
 * word_dict_add
 *
 * �P���o�^����B
 * ���ɓo�^�ς݂̒P��̏ꍇ�́A�J�E���^��+1����B
 *
 * @param [in]      *word   �P�ꕶ����
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
