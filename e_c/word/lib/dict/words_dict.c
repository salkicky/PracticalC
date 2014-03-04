#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "words_dict.h"

typedef struct _WORD_INFO_T {
	char *word;                             // �P��L���̈�ւ̃|�C���^
	int count;                              // �P��̓o�^��
    struct _WORD_INFO_T *bp;                // �O�̃��X�g�ւ̃|�C���^
	struct _WORD_INFO_T *np;                // ���̃��X�g�ւ̃|�C���^
} WORD_INFO_T;

typedef struct {
    WORD_INFO_T *head;                      // ���X�g�擪�ւ̃|�C���^
    WORD_INFO_T *curr;                      // ���X�g��Ɨ̈�
} DICT_T;

WORD_INFO_T *_alloc_wordinfo(char *word, int word_len);        // �P��Ǘ��̈���m�ۂ���
void _free_wordinfo(WORD_INFO_T *winfo);                        // �P��Ǘ��̈���������

/*********************************************************
 * word_dict_create_context
 * 
 * ���s�p�̃R���e�L�X�g�𐶐�����B
 * ���p�I����͕K�� word_dict_destroy_context()�ŉ�����邱�ƁB
 *
 * @return ���s�p�R���e�L�X�g�ւ̃|�C���^
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
 * �m�ۂ������s�p�R���e�L�X�g���������B
 *
 * @param [in]      *context ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_destroy_context(void *context)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *next;
    
    // �P�ꃊ�X�g�̉��
    dict->curr = dict->head;

    while (dict->curr != NULL) {
        printf("-----\n");
        printf("  curr->word = %s\n", dict->curr->word);
        printf("  curr->count = %d\n", dict->curr->count);

        next = dict->curr->np;
        _free_wordinfo(dict->curr);
        dict->curr = next;
    }

    // ���s�p�R���e�L�X�g�̉��
    free(context);
}

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
void word_dict_add(void *context, char *word, int word_len)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *winfo;

    if (word == NULL) {
        // �����񂪖��Z�b�g�Ȃ牽�����Ȃ�
        return;
    }

    //if (*word = '\0') {
    //    // �����񂪃k���ł��������Ȃ�
    //}
    
    //// word��T��
    //if (_serch(dictp, wordp) == FALSE) {
    //}

    // ������Γo�^
    
    // �n���ꂽ�P��̊Ǘ��̈���m��
    winfo = _alloc_wordinfo(word, word_len);

    // ���X�g�̌��ɘA������
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
 * �P�������o��
 *
 * @param [in]      *context    ���s�p�R���e�L�X�g
 * @param [out]     *word       �P�ꕶ����
 * @param [out]     counter     �o�^������
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

// �w�肵���P����T�[�`����
WORD_INFO_T *_search_from_dict(char *word)
{

}

// �P��̊Ǘ��̈���m�ۂ���
WORD_INFO_T *_alloc_wordinfo(char *word, int word_len)
{
    WORD_INFO_T *wp;

    // �P��̊Ǘ��̈���m��
    wp = (WORD_INFO_T *)malloc(sizeof(WORD_INFO_T));

    // �Ǘ�����P��̑傫���ɍ��킹�ė̈�m��
    wp->word = (char *)malloc(word_len+1);

    // �P��̕���������V���Ɋ��蓖�Ă��̈�փR�s�[���A�I�[������
    memcpy(wp->word, word, word_len);
    wp->word[word_len] = '\0';

    // ���̑��̗̈��������
    wp->count = 1;
    wp->np = NULL;
    wp->bp = NULL;

    return wp;
}

// �P��̊Ǘ��̈���������
void _free_wordinfo(WORD_INFO_T *winfo)
{
    free((void *)winfo->word);
    free((void *)winfo);
}
