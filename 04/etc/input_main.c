#include <stdio.h>


int main(int argc, int argv[])
{
    int i = 0;

    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
