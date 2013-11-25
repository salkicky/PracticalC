#include <stdio.h>

/* �v���g�^�C�v�錾 */
void print_space(int total_stairs, int stairs);
void print_astah(int total_stairs, int stairs);

/**
 * main
 */
int main()
{
    char line[80];          /* ���͎�荞�ݗp�o�b�t�@ */
    int total_stairs;       /* �i�� */
    int n;                  /* ���[�v�J�E���^ */

    /* �i���̓��͒l����荞�� */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &total_stairs) == 0) {
        printf("Error : Input Value is not Number.\n");
        exit(8);
    }

    /* �o�� */
    /* ���߂́����o�͂��� */
    for (n = 0; n < total_stairs; n++) {
        print_space(total_stairs, n);
        print_astah(total_stairs, n);
        printf("\n");
    }

    /* ��́����o�͂��� */
    for (n = (total_stairs - 2); 0 <= n; n--) {
        print_space(total_stairs, n);
        print_astah(total_stairs, n);
        printf("\n");
    }

    return 0;
}

/**
 * print_space : �󔒂��o�͂���
 * [in] int total_stairs        �S�i��
 * [in] int stairs              �󎚒��̒i��
 */
void print_space(int total_stairs, int stairs)
{
    int space_cnt;

    for (space_cnt = 0; space_cnt < (total_stairs - stairs - 1); space_cnt++) {
        printf(" ");
    }
}

/**
 * print_astah : �A�X�^���X�N���o�͂���B
 * [in] int total_stairs        �S�i��
 * [in] int stairs              �󎚒��̒i��
 * */
void print_astah(int total_stairs, int stairs)
{
    int astah_cnt;

    for (astah_cnt = 0; astah_cnt < (2*stairs + 1); astah_cnt++) {
        printf("*");
    }
}
