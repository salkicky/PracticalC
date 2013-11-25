#ifndef _GET_WORD_H_
#define _GET_WORD_H_

#include <stdio.h>

/*********************************************************
 * get_word
 *
 * �X�g���[������P���1�������o���B
 * '_'�ŘA�����ꂽ�p�����͍��킹��1�P��Ƃ���B
 * EOF�܂��͉p�����ȊO�̕��������o�����ꍇ�́A�P���؂�
 * �Ɣ��f���ďI������B
 *
 * @param [in,out]  bufp    �P��擾�p�o�b�t�@
 * @param [in]      size    �P��擾�p�o�b�t�@�T�C�Y
 * @param [in,out]  fp      �t�@�C���X�g���[��
 *
 * @return �P��̕������iEOF�����o�����ꍇ��-1��Ԃ��j
 *********************************************************/
int get_word(char *bufp, int size, FILE *fp);


#endif // _GET_WORD_H_
