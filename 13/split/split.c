#include <stdio.h>


/**
 * my_strchr
 *      文字列から指定文字の位置を検索し、ポインタとして返す
 * in : char *string_ptr        検索対象となる文字列へのポインタ
 * in : char find               検索する文字
 * out: char *                  検索した結果へポインタ
 * out: NULL                    見つからなかった場合はNULLを返す
 * */
char *my_strchr(char *string_ptr, char find)
{
    while (*string_ptr != find) {
        /* 文字列の終端をチェック */

        if (*string_ptr == '\0') {
            /* 終端なら抜ける */
            return (NULL);
        }

        string_ptr++;
    }

    /* 検索文字へのポインタを返す */
    return string_ptr;
}


/*-----------------------
 * main
 * ---------------------- */
int main()
{
    char line[80];
    char *first_ptr;
    char *last_ptr;

    printf("Please Input Your Name.(ex. 'nnn/xxx') > ");
    fgets(line, sizeof(line), stdin);

    /* 入力行最後の改行を終端文字列に入れ替える */
    line[strlen(line)-1] = '\0';

    last_ptr = line;
    first_ptr = my_strchr(line, '/');

    /* エラーをチェック */
    if (first_ptr == NULL) {
        printf("Error : Unable to find slash in %s\n", line);
        exit(8);
    }

    /* 文字列を姓名に分割 */
    *first_ptr = '\0';
    first_ptr++;

    printf("First:%s\nLast:%s\n", first_ptr, last_ptr);
    return 0;
}
