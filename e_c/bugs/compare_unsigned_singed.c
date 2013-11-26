#include <stdio.h>

int main(void)
{
    int d = -1;
    unsigned int ud = 2;

    if (ud > d)
    {
        printf("-1 < 2\n");
    }
    else
    {
        printf("-1 >= 2\n");
    }

    return 0;
}

