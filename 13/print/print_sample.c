#include <stdio.h>

int main(int argc, char *argv[])
{
    char *program_name_ptr = *argv;
    argv++;
    argc--;

    while (argc > 0) {
        printf("%s\n", *argv);

        if ((*argv)[0] == '-') {
            switch ((*argv)[1]) {
                case 'o':
                    printf("get o\n");
                    break;
                case 's':
                    printf("get s\n");
                    break;
                default:
                    break;
            }
        }

        argv++;
        argc--;
    }
    return 0;
}
