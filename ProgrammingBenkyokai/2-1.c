#include <stdio.h>

/**
 * main
 **/
int main()
{
    char line[80];
    int max_check_num;
    int check_num;
    int prime_counter;

    int i;

    /* �`�F�b�N�������� */
    printf("Please input number > ");
    fflush(stdout);
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &max_check_num);

    prime_counter = 0;

    /* 1������͂��ꂽ���l�܂ŏ��Ԃɑf�����ǂ������`�F�b�N���� */
    for (check_num = 1; check_num < max_check_num; check_num++) {
        /* check_num���f�����ǂ����H�̔��� */
        for (i = 2; i < check_num; i++) {
            if ((check_num % i) == 0) {
                /* ����؂��Ȃ�f���ł͂Ȃ��̂Ŕ����� */
                break;
            }
        }

        /* �f���Ȃ�J�E���g */
        if (i == check_num) {
            prime_counter++;
        }
    }

    printf("prime count : %d\n", prime_counter); 

    return 0;
}
