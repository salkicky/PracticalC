/********************************************************
 * �ۑ�2-2
 * 
 * �^����ꂽ���l��f�����������ĕ\������B
 *********************************************************/
#include <stdio.h>


#define MAX_PRIME_LIST 100

/*
 * �v���g�^�C�v�錾
 */
int init_prime(void);
int get_next_prime(int current_prime);

/*
 * main
 */
int main()
{
    char line[80];                              /* ���̓o�b�t�@     */
    int check_num;                           /* �m�F���̔ԍ�     */
    int cnt;                                    /* ���[�v�J�E���^   */

    int prime;

    int prime_decomp[MAX_PRIME_LIST];
    int d_index;

    // �f�����������鐔�l���擾
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &check_num) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    // ������
    prime = init_prime();
    d_index = 0;

    while (1) {
        /*
         * check_num ���f���ł��邩�H���`�F�b�N
         */
        if (check_num <= prime) {
            // check_num ���f���Ŋ���؂�Ȃ���ΏI��
            prime_decomp[d_index] = check_num;
            d_index++;
            break;
        }

        if ((check_num % prime) == 0) {
            /* ����؂��f�������݂��Ă����Ȃ� */
            /* �v�f�Ƃ��ċL�� */
            prime_decomp[d_index] = prime;
            d_index++;
            /* �������l�����̃��[�v�Ń`�F�b�N���鐔�Ƃ��čX�V */
            check_num = check_num / prime;
            prime = init_prime();
        } else {
            /* ����؂�Ȃ���΁A���ɑ傫���f����T�� */
            prime = get_next_prime(prime);
        }
    }

    printf("-------------------\n");
    for (cnt = 0; cnt < d_index; cnt++) {
        printf("%d\n", prime_decomp[cnt]);
    }
    
    return 0;
}


/***********************************************
 * init_prime  �ł��������f����Ԃ�
 ***********************************************/
int init_prime(void)
{
    return 2;
}


/***********************************************
 * get_next_prime  ���̑f����T��
 *
 * �����ŗ^����ꂽ���l�����傫���f����Ԃ� 
 ***********************************************/
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
