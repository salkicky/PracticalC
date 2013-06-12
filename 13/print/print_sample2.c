/***********************************************************
 * 13.8
 *      ��13-12���O�̃R�}���h���C���I�v�V���������̕��@��
 *      �����ڂɂ킩��ɂ����R�[�h���������߁A�p�b�ƌ���
 *      �킩��悤�ɏ����������B
 ***********************************************************/
#include <stdio.h>

/*-------------------------------------------------------
 * main -- �R�}���h���C���������󎚂���
 *-------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i;
    char *program_name_ptr;

    /* �v���O���������擾 */
    program_name_ptr = argv[0];
    printf("program name = %s\n", program_name_ptr);

    /* �R�}���h���C�����������ɉ�� */
    for (i=1; i < argc; i++) {
        printf("%d %s\n", i, argv[i]);

        if (argv[i][0] == '-') {
            /* �R�}���h���C���I�v�V�����̉�� */
            switch (argv[i][1]) {
                case 'o':
                    /* -o */
                    printf("  get '-o' option.\n");
                    i++;
                    printf("     %s\n", argv[i]);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
