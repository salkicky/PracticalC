#ifndef _GET_WORD_H_
#define _GET_WORD_H_

#include <stdio.h>

/*********************************************************
 * get_word
 *
 * �X�g���[������P���1���o���B
 * �P��̋�؂�́AEOF�܂��͉p�����ȊO�Ƃ���B
 * //�P��̋�؂�́AEOF�܂��̓X�y�[�X�A���s�A�^�u�����Ƃ���B
 *
 * @param [in,out]  wordp   �P��i�[�p�o�b�t�@
 * @param [in]      size    �P��i�[�p�o�b�t�@�T�C�Y
 * @param [in,out]  fp      �t�@�C���X�g���[��
 *
 * @return �P��̕������iEOF�����o�����ꍇ��-1��Ԃ��j
 *********************************************************/
int get_word(char *wordp, int size, FILE *fp);


#endif // _GET_WORD_H_
