#include <stdio.h>

int main()
{
    int thing_var;
    int *thing_ptr;

    thing_var = 2;
    printf("Thing %d\n", thing_var);

    thing_ptr = &thing_var;

    *thing_ptr = 4;

    printf("Thing %d\n", thing_var);

    return 0;

}
