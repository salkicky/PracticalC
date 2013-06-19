/*****************************************************
 * ���K14-1
 *
 * �t�@�C����ǂ݁A���̍s���𐔂���v���O����
 *****************************************************/
#include <stdio.h>


int main(int argc, char *argv[])
{
    unsigned int    lcount;                 /* �s���J�E���^�l       */
    FILE            *in_file;               /* ���̓t�@�C�����ʎq   */
    int             read_char;              /* �ǂݏo������         */

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
        

        if (read_char == EOF) {
            // EOF or Error
            break;
        }

        // check character
        if (read_char == '\n') {
            // count line
            lcount++;
        }
    }

    printf("[%s] has [%d] line\n", argv[1], lcount);
    return 0;
}
