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

    int prime;

    int prime_decomp[100];
    int d_index;

    /* ���l����� */
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_number) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    d_index = 0;
    check_number = input_number;

    while (1) {

        /* �f���̃��X�g���擾���� */
        prime = 0; 

        while (1) {
            prime = get_prime(prime);
            if (check_number <= prime) {
                /* �I�� */ 
                break;
            }

            if ((check_number % prime) == 0) {
                /* �v�f�Ƃ��ċL�� */
                prime_decomp[d_index] = prime;
                d_index++;
                /* �������l�����̃��[�v�Ń`�F�b�N���鐔�Ƃ��čX�V */
                check_number = check_number / prime;
            }
        }

        if (check_number <= prime) {
            /* ��������؂�Ȃ��̂ŏI�� */
            prime_decomp[d_index] = check_number;
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

int get_prime(int min_prime)
{
    int i;
    int prime = min_prime;

    for (i = min_prime; 
}
