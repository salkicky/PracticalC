#include <stdio.h>

/********************************************************
 * main -- �f������������
 * 
 *
 *********************************************************/
int main()
{
    char line[80];
    int input_number;

    int check_number;
    int cnt;

    /* ���l����� */
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_number) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }


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
