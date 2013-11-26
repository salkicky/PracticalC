#include <ctype.h>
#include "get_word.h"

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
int get_word(char *wordp, int size, FILE *fp)
{
    int ch;
    int len;

    len = 0;

    while (1) {
        ch = getc(fp);
        if (ch == EOF) {
            break;
        }

        //if ((ch != ' ') && (ch != '\t') && (ch != '\n')) {
        if (isalnum(ch)) {
            // �p�����܂���'_'�Ȃ�
            wordp[len] = ch;
            len++;
        }
        else {
            if (len != 0) {
                // ���łɕ����擾�ς݂Ȃ�P���؂�Ɣ��f���ďI��
                break;
            }
        }
    }
    wordp[len] = '\0';

    if (ch == EOF) {
        return -1;
    }

    return len;
}
