#include <ctype.h>
#include "get_word.h"

/*********************************************************
 * get_word
 *
 * �X�g���[������P���1�������o���B
 * EOF�܂��͉p�����ȊO�̕��������o�����ꍇ�́A�P���؂�
 * �Ɣ��f���ďI������B
 *
 * @param [in,out]  bufp    �P��擾�p�o�b�t�@
 * @param [in]      size    �P��擾�p�o�b�t�@�T�C�Y
 * @param [in,out]  fp      �t�@�C���X�g���[��
 *
 * @return �P��̕������iEOF�����o�����ꍇ��-1��Ԃ��j
 *********************************************************/
int get_word(char *bufp, int size, FILE *fp)
{
    int ch;
    int len;

    len = 0;

    while (1) {
        ch = getc(fp);
        if (ch == EOF) {
            break;
        }

        if (isalnum(ch)) {
            // �p�����Ȃ�
            bufp[len] = ch;
            len++;
        }
        else {
            if (len != 0) {
                // ���łɕ����擾�ς݂Ȃ�P���؂�Ɣ��f���ďI��
                break;
            }
        }
    }

    if (ch == EOF) {
        return -1;
    }

    bufp[len] = '\0';
    return len;
}
