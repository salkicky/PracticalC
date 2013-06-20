/*****************************************************
 * 実習14-4
 *
 * 数値のリストを含むASCIIファイルを読み、同じリストを含む
 * バイナリファイルに書き込むプログラムを作成してください。
 * また、逆方向に読み出し、書き込みを行うプログラムも作成
 * してくだだい。こうすれば、プログラムが適切に動作している
 * かどうかをチェックできます。
 * ****************************************************/

#include <stdio.h>


int main(int argc, char *argv[])
{
    char *in_file_name;
    char *out_file_name;

    FILE *in_file;
    FILE *out_file;

    //////////////////////////////////////
    // get parameters

    if (argc != 3) {
        fprintf(stderr, "Error : command format error\n");
        fprintf(stderr, "Usage : [exe] [input file] [output file]\n");
        exit(8);
    }

    in_file_name    = argv[1];
    out_file_name   = argv[2];

    //////////////////////////////////////
    // open file
    in_file = fopen(in_file_name, "r");

}
