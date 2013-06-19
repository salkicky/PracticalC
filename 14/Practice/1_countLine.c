/*****************************************************
 * 実習14-1
 *
 * ファイルを読み、その行数を数えるプログラム
 *****************************************************/
#include <stdio.h>


int main(int argc, char *argv[])
{
    unsigned int    lcount;                 /* 行数カウンタ値       */
    FILE            *in_file;               /* 入力ファイル識別子   */
    int             read_char;              /* 読み出し文字         */

    // check parameters
    if (argc != 2) {
        fprintf(stderr, "Error : Command format error.\n");
        fprintf(stderr, "Usage : [command] [file name]\n");
        exit(8);
    }

    // open file
    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s%]\n", argv[1]);
        exit(8);
    }

    // initialize
    lcount = 0;
    
    // count '\n'
    while (1) {
        // read character from file
        read_char = fgetc(in_file);

        if (ferror(in_file) != 0) {
            // Error
            fprintf(stderr, "Error : Cannot read file [%s]\n", argv[1]);
            exit(8);
        }

        // check character
        if (read_char == EOF) {
            // End Of File
            break;
        }

        if (read_char == '\n') {
            // count line
            lcount++;
        }
    }

    printf("[%s] has [%d] line\n", argv[1], lcount);
    return 0;
}
