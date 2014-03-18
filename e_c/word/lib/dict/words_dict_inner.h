#ifndef _INNER_WORDS_DICT_H_
#define _INNER_WORDS_DICT_H_

struct _WORD_INFO_T {
	char *word;                             // �P��L���̈�ւ̃|�C���^
	int count;                              // �P��̓o�^��
    struct _WORD_INFO_T *bp;                // �O�̃��X�g�ւ̃|�C���^
	struct _WORD_INFO_T *np;                // ���̃��X�g�ւ̃|�C���^
};
typedef struct _WORD_INFO_T WORD_INFO_T;

struct DictionaryContext_tag {
    WORD_INFO_T *head;                      // ���X�g�擪�ւ̃|�C���^
    WORD_INFO_T *curr;                      // ���X�g��Ɨ̈�
};
//typedef struct DictionaryContext_tag DICT_T;

#endif // _INNER_WORDS_DICT_H_
