#include <stdio.h>

/* �v���g�^�C�v�錾 */
void print_space(int total_stairs, int stairs);
void print_astah(int total_stairs, int stairs);

/**
 * main
 */
int main()
{
    char line[80];
    int total_stairs;     /* �i�� */
    int n;
    int space_cnt;
    int astah_cnt;

    /* �i���̓��� */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &total_stairs);

    /* �o�� */
    for (n = 1; n <= total_stairs; n++) {
        print_space(total_stairs, n);
        print_astah(total_stairs, n);
        printf("\n");
    }

    for (n = (total_stairs - 1); 0 < n; n--) {
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

    for (space_cnt = 1; space_cnt <= (total_stairs - stairs); space_cnt++) {
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

    for (astah_cnt = 1; astah_cnt <= (2*stairs -1); astah_cnt++) {
        printf("*");
    }
}
