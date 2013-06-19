/**************************
 * 例14-4
 *
 **************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cur_char;               /* 書き出す文字 */
    FILE *out_file;             /* 出力ファイル */

    out_file = fopen("test.out", "w");
    if (out_file == NULL) {
        fprintf(stderr, "Error : Cannot open output file\n");
        exit(8);
    }

    for (cur_char = 0; cur_char < 128; cur_char++) {
        fputc(cur_char, out_file);
    }

    fclose(out_file);
    return 0;
}
