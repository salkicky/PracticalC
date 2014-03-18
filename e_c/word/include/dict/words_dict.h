#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

#define DICT_RET_OK     (1)
#define DICT_RET_NG     (0)

struct DictionaryContext_tag;
typedef struct DictionaryContext_tag DICT_T;

/*********************************************************
 * word_dict_create_context
 * 
 * ���s�p�̃R���e�L�X�g�𐶐�����B
 * ���p�I����͕K�� word_dict_destroy_context()�ŉ�����邱�ƁB
 *
 * @param [out] ���s�p�R���e�L�X�g�ւ� pointer to pointer
 * @return DICT_RET_OK  ����I��
 * @return DICT_RET_NG  �ُ�I��
 *********************************************************/
int word_dict_create_context(struct DictionaryContext_tag **contextp);

/*********************************************************
 * word_dict_destroy_context
 *
 * �m�ۂ������s�p�R���e�L�X�g���������B
 *
 * @param [in]      *context ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_destroy_context(struct DictionaryContext_tag *context);

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
void word_dict_register(struct DictionaryContext_tag *context, char *word, int word_len);

/*********************************************************
 * word_dict_move_head
 *
 * ������擪�ɖ߂�
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_move_head(struct DictionaryContext_tag *context);

/*********************************************************
 * word_dict_get_a_word
 *
 * �P�������o��
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 * @param [out]     *word       �P�ꕶ����
 * @param [out]     counter     �o�^������
 * @return DICT_RET_OK      ��肾������
 * @return DICT_RET_NG      ��肾�����s
 *********************************************************/
int word_dict_get_a_word(struct DictionaryContext_tag *context, char **wordp, int *counter);

int word_dict_get_word_count(struct DictionaryContext_tag *context, char *wordp, int *counter);

#endif //_WORDS_DICT_H_
