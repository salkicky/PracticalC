/********************************************************
 * �ۑ�2-2
 * 
 * �^����ꂽ���l��f�����������ĕ\������B
 *********************************************************/
#include <stdio.h>

int main()
{
    char line[80];                              /* ���̓o�b�t�@     */
    int input_number;                           /* ���͒l           */
    int check_number;                           /* �m�F���̔ԍ�     */
    int cnt;                                    /* ���[�v�J�E���^   */

    /* ���l����� */
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_number) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    check_number = input_number;

    /* �f����T�� */
    
    /* �f��������� */
    check_number /= prime_number;

    /* �f�����Ȃ���� �� �I�� */
    


    /* �f�����X�g�̏��������Ɋ���؂�邩�`�F�b�N */
    /* ����؂ꂽ�炻�̒l���i�[����B*/
    /* ����؂ꂽ��`�F�b�N���鐔�l���X�V */
    

    /* �܂��f���̃��X�g���쐬���� */

    /* ���ɁA�f���̃��X�g�̒�����A���͒l������؂�邩�H���m�F���� */
    // 4
    while (input_number > 1) {
        for (cnt = 2; cnt < input_number; cnt++) {
            if (input_number % cnt == 0
        }
        input_number--;
    }
    
}

/************************************************************
 * �͈͓��ň�ԏ������f����T��
 * 
 * [in]  int max_number
 * [out] int �ŏ��f��
 *************************************************************/
