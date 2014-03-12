#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "words_dict.h"
#include "inner_words_dict.h"

#define B_TRUE  1
#define B_FALSE 0

typedef int _BOOL;


// -----------------------------------------
// �v���g�^�C�v�錾
// -----------------------------------------
_BOOL _search_from_dict(DICT_T *dict, char *word, WORD_INFO_T **match);
WORD_INFO_T *_alloc_wordinfo(char *word, int word_len);         // �P��Ǘ��̈���m�ۂ���
void _free_wordinfo(WORD_INFO_T *winfo);                        // �P��Ǘ��̈���������

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
int word_dict_create_context(struct DictionaryContext_tag **contextp)
{
    DICT_T *dict;

    dict = (DICT_T *)malloc(sizeof(DICT_T));
    if (dict == NULL) {
        // �������m�ێ��s
        return DICT_RET_NG;
    }

    dict->head = NULL;
    dict->curr = NULL;

    *contextp = dict;

    return DICT_RET_OK;
}

/*********************************************************
 * word_dict_destroy_context
 *
 * �m�ۂ������s�p�R���e�L�X�g���������B
 *
 * @param [in]      *context ���s�p�R���e�L�X�g
 *********************************************************/
void word_dict_destroy_context(struct DictionaryContext_tag *context)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *next;
    
    // �P�ꃊ�X�g�̉��
    dict->curr = dict->head;

    while (dict->curr != NULL) {
        next = dict->curr->np;
        _free_wordinfo(dict->curr);
        dict->curr = next;
    }

    // ���s�p�R���e�L�X�g�̉��
    free(context);
}

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
void word_dict_register(struct DictionaryContext_tag *context, char *word, int word_len)
{
    DICT_T *dict = (DICT_T *)context;
    WORD_INFO_T *match;
    WORD_INFO_T *winfo;
    _BOOL    ret; 

    if (word == NULL) {
        // �����񂪖��Z�b�g�Ȃ牽�����Ȃ�
        return;
    }

    if (dict->head != NULL) {
        // ����łȂ����
        ret = _search_from_dict(dict, word, &match);
        if (ret == B_TRUE) {
            // �o�^�ς݂Ȃ�J�E���g
            match->count++;
        } else {
            // ���o�^�Ȃ�P���o�^

            // �n���ꂽ�P��̊Ǘ��̈���m��
            winfo = _alloc_wordinfo(word, word_len);

            // ���X�g�̌��ɘA������
            winfo->bp = dict->curr;
            (dict->curr)->np = winfo;
            dict->curr = winfo;
        }
    } else {
        // ����Ȃ�

        // �n���ꂽ�P��̊Ǘ��̈���m��
        winfo = _alloc_wordinfo(word, word_len);

        // ���X�g�̌��ɘA������
        dict->head = winfo;
        dict->curr = winfo;
    }
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
void word_dict_get_a_word(struct DictionaryContext_tag *context, char **wordp, int *counter)
{
    DICT_T *dict = (DICT_T *)context;

    *wordp = NULL;
    *counter = 0;

    if (dict->curr != NULL) {
        *wordp = dict->curr->word;
        *counter = dict->curr->count;
    }
}

//=================================================================

// �w�肵���P����T�[�`����
_BOOL _search_from_dict(DICT_T *dict, char *word, WORD_INFO_T **match)
{
    dict->curr = dict->head;

    while (dict->curr != NULL) {

        if (strcmp(word, dict->curr->word) == 0) {
            // �����񂪈�v������
            *match = dict->curr;
            break;
        }

        if (dict->curr->np == NULL) {
            return B_FALSE;
        }
        dict->curr = dict->curr->np;
    }

    return B_TRUE;
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
