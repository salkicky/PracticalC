#include <stdio.h>
#include <string.h>


/*******************************
 * �d�l�F
 *      ���͂��ꂽ���l�𑫂�������B
 *      '0'����͂��ꂽ�甲����B
 *******************************/
int main()
{
    char line[80];
    int total = 0;
    int input_num = 0;
    int scan_length = 0;

    while(1) {
        /* ���͐��l�̏����� */
        input_num  = 0;

        /* ���l���� */
        printf("please input number : ");
        fgets(line, sizeof(line), stdin);
        scan_length = sscanf(line, "%d", &input_num);

        /* ���� */
        if (scan_length == 0) {
            /* ���͂��ꂽ�����������łȂ���� */
            printf("[ERROR] you input wrong number! please retry.\n");
        } else if(input_num == 0) {
            /* 0 ����͂Ŕ����� */
            printf("bye\n");
            break;
        } else {
            /* �����܂Ő���Ȃ���Z */
            total += input_num;
        }
        printf("  total = %d\n", total);
    }

    return (0);
}
