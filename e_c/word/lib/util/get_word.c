#include <ctype.h>
#include "get_word.h"

/*********************************************************
 * get_word
 *
 * ストリームから単語を1つ取り出す。
 * 単語の区切りは、EOFまたは英数字以外とする。
 * //単語の区切りは、EOFまたはスペース、改行、タブ文字とする。
 *
 * @param [in,out]  wordp   単語格納用バッファ
 * @param [in]      size    単語格納用バッファサイズ
 * @param [in,out]  fp      ファイルストリーム
 *
 * @return 単語の文字数（EOFを検出した場合は-1を返す）
 *********************************************************/
int get_word(char *wordp, int size, FILE *fp)
{
    int ch;
    int len;

    len = 0;

    while (1) {
        ch = getc(fp);
        if (ch == EOF) {
            break;
        }

        //if ((ch != ' ') && (ch != '\t') && (ch != '\n')) {
        if (isalnum(ch)) {
            // 英数字または'_'なら
            wordp[len] = ch;
            len++;
        }
        else {
            if (len != 0) {
                // すでに文字取得済みなら単語区切りと判断して終了
                break;
            }
        }
    }
    wordp[len] = '\0';

    if (ch == EOF) {
        return -1;
    }

    return len;
}
