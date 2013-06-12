#include <stdio.h>
#include <string.h>

/************************************
 * tmp-name -- 一時的なファイル名を返す
 *
 * この関数は、呼び出されるたびに、新しい名前を返す
 *
 * out : 新しいファイル名を指すポインタ
 *************************************/
char *tmp_name(void)
{
    static char name[30];       /* 生成する名前         */
    static int sequence = 0;    /* 最後につける通し番号 */

    ++sequence;

    strcpy(name, "tmp-");

    /* 通し番号を付ける */
    name[4] = sequence + '0';

    /* 文字列を終了 */
    name[5] = '\0';
    return name;

}

/****
 * main
 ******/
int main()
{
    int i;

    for (i=0; i < 20; i++) {
        printf("%s\n", tmp_name());
    }
    return 0;
}
