/********************************
 * 14.5 バイナリIOのサンプル 
 *
 *
 ************************************/
#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *in_file;

    struct {
        int width;
        int height;
    } rectangle;
    
    int read_size;

    in_file = fopen("test.out", "r");
    if (in_file == NULL) {
        printf("Error : Cannot open test.out\n");
        exit(8);
    }

    read_size = fread((char *)&rectangle, 1, sizeof(rectangle), in_file);
    if (read_size != sizeof(rectangle)) {
        fprintf(stderr, "Error : Unable to read rectangle\n");
        exit(8);
    }

    printf("rectangle.width = %x, .height = %x\n", rectangle.width, rectangle.height);
    return 0;
}
