#include <stdio.h>

int main()
{
    char buffer[20];
    char data = '*';

    memset(buffer, '-', 10);
    memset(buffer, '*', 4);
    buffer[10] = '\0';

    printf("%s\n", buffer);

    return 0;
}
