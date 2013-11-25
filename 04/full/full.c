#include <stdio.h>
#include <string.h>

char first[100];
char last[100];
char full[100];

int main()
{
    int n = 0;

    printf("Input Your first name > ");
    fgets(first, sizeof(first), stdin);
    n = sscanf(first, "%s\n", first);
    if (n < 0) {
        printf("# Error %d\n", n);
        return 1;
    }

    printf("Input Your last name > ");
    fgets(last, sizeof(last), stdin);
    sscanf(last, "%s\n", last);
    if (n < 0) {
        printf("# Error %d\n", n);
        return 1;
    }

    strcat(full, first);
    strcat(full, " ");
    strcat(full, last);

    printf("------\n"); 
    printf("full name is %s\n", full);
    printf("------\n"); 

    return 0;

}
