/********************************************************
 * �ۑ�2-2
 * 
 * �^����ꂽ���l��f�����������ĕ\������B
 *********************************************************/
#include <stdio.h>

/*
 * �v���g�^�C�v�錾
 */
int get_next_prime(int current_prime);


/*
 * main
 */
int main()
{
    char line[80];                              /* ���̓o�b�t�@     */
    int input_num;                           /* ���͒l           */
    int check_num;                           /* �m�F���̔ԍ�     */
    int cnt;                                    /* ���[�v�J�E���^   */

    int prime;

    int prime_decomp[100];
    int d_index;

    // �f�����������鐔�l���擾
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_num) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    d_index = 0;
    check_num = input_num;

    while (1) {
        // ������
        prime = 2; 

        /*
         * check_num ���f���ł��邩�H���`�F�b�N
         */
        while (1) {
            prime = get_next_prime(prime);
            if (check_num <= prime) {
                /* �I�� */ 
                break;
            }

            if ((check_num % prime) == 0) {
                /* �v�f�Ƃ��ċL�� */
                prime_decomp[d_index] = prime;
                d_index++;
                /* �������l�����̃��[�v�Ń`�F�b�N���鐔�Ƃ��čX�V */
                check_num = check_num / prime;
            }
        }

        /*
         * �I������ 
         */
        if (check_num <= prime) {
            // check_num ���f���Ȃ�I��
            prime_decomp[d_index] = check_num;
            d_index++;
            break;
        }
    }

    printf("-------------------\n");
    for (cnt = 0; cnt < d_index; cnt++) {
        printf("%d\n", prime_decomp[cnt]);
    }
    
    return 0;
}

int get_next_prime(int current_prime)
{
    int i;
    int check_num;
    int next_prime = current_prime;

    for (check_num = (current_prime + 1); ; check_num++) {
        for (i = 2; i < check_num; i++) {
            if ((check_num % i) == 0) {
                // ����؂��Ȃ�f���ł͂Ȃ��̂Ŕ�����
                break;
            }
        }

        if (i = check_num) {
            // �f���Ȃ�
            next_prime = check_num;
            break;
        }
    }

    return next_prime;
}
