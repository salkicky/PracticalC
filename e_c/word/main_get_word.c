#include <stdio.h>
#include "get_word.h"

int main(void)
{
    char word_buf[256];

    printf("This program separates words from sentence.\n");
    printf("Please input sentence >\n");
    fflush(stdout);

    while (get_word(word_buf, 256, stdin) != -1) {
        printf("<<%s>>\n", word_buf);
        fflush(stdout);
    }

    return 0;
}
