#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

/*********************************************************
 * word_dict_create_context
 * 
 * ���s�p�̃R���e�L�X�g�𐶐�����B
 * ���p�I����͕K�� word_dict_destroy_context()�ŉ�����邱�ƁB
 *
 * @return ���s�p�R���e�L�X�g�ւ̃|�C���^
 *********************************************************/
void *word_dict_create_context(void);

/*********************************************************
 * word_dict_destroy_context
 *
 * �m�ۂ������s�p�R���e�L�X�g���������B
 *
 * @param [in]      *context ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_destroy_context(void *context);

/*********************************************************
 * word_dict_add
 *
 * �P���o�^����B
 * ���ɓo�^�ς݂̒P��̏ꍇ�́A�J�E���^��+1����B
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 * @param [in]      *word       �P�ꕶ����
 * @param [in]      word_len    �o�^����P��̕�����
 *********************************************************/
void word_dict_add(void *context, char *word, int word_len);

/*********************************************************
 * word_dict_get_a_word
 *
 * �P�������o��
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 * @param [out]     *word       �P�ꕶ����
 * @param [out]     counter     �o�^������
 *********************************************************/
void word_dict_get_a_word(void *context, char **wordp, int *counter);


#endif //_WORDS_DICT_H_