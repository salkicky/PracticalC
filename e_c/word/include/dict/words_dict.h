#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

#include "type.h"

struct _DICT_T;
typedef struct _DICT_T DICT_T;

/*********************************************************
 * word_dict_create_context
 * 
 * ���s�p�̃R���e�L�X�g�𐶐�����B
 * ���p�I����͕K�� word_dict_destroy_context()�ŉ�����邱�ƁB
 *
 * @param [out] ���s�p�R���e�L�X�g�ւ� pointer to pointer
 * @return B_TRUE   ����I��
 * @return B_FALSE  �ُ�I��
 *********************************************************/
_BOOL word_dict_create_context(DICT_T **contextp);

/*********************************************************
 * word_dict_destroy_context
 *
 * �m�ۂ������s�p�R���e�L�X�g���������B
 *
 * @param [in]      *context ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_destroy_context(DICT_T *context);

/*********************************************************
 * word_dict_register
 *
 * �P���o�^����B
 * ���ɓo�^�ς݂̒P��̏ꍇ�́A�J�E���^��+1����B
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 * @param [in]      *word       �P�ꕶ����
 * @param [in]      word_len    �o�^����P��̕�����
 *********************************************************/
void word_dict_register(DICT_T *context, char *word, int word_len);

/*********************************************************
 * word_dict_move_head
 *
 * ������擪�ɖ߂�
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_move_head(DICT_T *context);

/*********************************************************
 * word_dict_get_a_word
 *
 * �P�������o��
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 * @param [out]     *word       �P�ꕶ����
 * @param [out]     counter     �o�^������
 * @return B_TRUE      ��肾������
 * @return B_FALSE     ��肾�����s
 *********************************************************/
_BOOL word_dict_get_a_word(DICT_T *context, char **wordp, int *counter);

_BOOL word_dict_get_word_count(DICT_T *context, char *wordp, int *counter);

#endif //_WORDS_DICT_H_
