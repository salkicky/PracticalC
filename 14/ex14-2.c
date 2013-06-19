/*****************************
 * ��14-2
 *
 * sscanf �̖߂�l���g�p����
 *******************************/
#include <stdio.h>

int main()
{
    char line[80];      /* ���͍s */
    int count, total;   /* �G���g�����Ɠ��v�l */
    int scan_count;     /* ���ׂ�ꂽ�p�����[�^�̐� */

    /* �G���g�����Ɠ��v�l�̓��͎�t */
    fgets(line, sizeof(line), stdin);
    scan_count = sscanf(line, "%d %d", &count, &total);

    switch (scan_count) {
        case EOF:
        case 0:
            printf("Didn't fine any number\n");
            break;
        case 1:
            printf("Found 'coun'(%d), but not 'total'\n", count);
            break;
        case 2:
            printf("Found 'count'(%d) and 'total'(%d)\n", count, total);
            break;
        default:
            /* ���� */
            break;
    }

    return 0;
}
