#include <stdio.h>
#include "get_word.h"


int main(int argc, char *argv[])
{
    char bufp[256];
    int len;
    FILE *fp;
    int wc;

    len = 0;
    wc = 0;

    // 引数チェック
    if (argc < 2) {
        printf("ERROR : argument_error\n");
        printf("usage .... [exe] [file_name]\n");
        return -1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Cannot open file <<%s>>\n", argv[1]);
        return -1;
    }

    // ファイル内から単語を抜き出してカウントする
    while (get_word(bufp, 256, fp) != -1) {
        printf("<<%s>>\n", bufp);
        wc++;
    }

    printf(" ---------------------- \n");
    printf("wc\n");
    printf("%d\n", wc);

    fclose(fp);

    return 0;
}
