#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count = 0;          /* number or charactor */
    char *filename_ptr;
    FILE *in_file;          /* input file */

    /* charactor or EOF */
    int ch;

    if (argc != 2) {
        printf("Error : command format error.\n");
        printf("      : [exec] [file name]\n");
        exit(8);
    }

    filename_ptr = argv[1];

    in_file = fopen(filename_ptr, "r");
    if (in_file == NULL) {
        printf("Error : Cannot open%s\n", filename_ptr);
        exit(8);
    }

    while (1) {
        ch = fgetc(in_file);
        if (ch == EOF) {
            break;
        }
        count++;
    }

    printf("Number of characters in %s is %d\n", filename_ptr, count);

    fclose(in_file);
    return (0);
}
