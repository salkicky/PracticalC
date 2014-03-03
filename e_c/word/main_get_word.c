#include <stdio.h>
#include "get_word.h"

#define MAX_LEN 256

int main(void)
{
    char word_buf[MAX_LEN];

    printf("This program separates words from sentence.\n");
    printf("Please input sentence >\n");
    fflush(stdout);

    while (1) {
        while (get_word(word_buf, MAX_LEN, stdin) != -1) {
            printf("<<%s>>\n", word_buf);
            fflush(stdout);
        }

        printf("Please input sentence >\n");
        fflush(stdout);
    }

    return 0;
}
