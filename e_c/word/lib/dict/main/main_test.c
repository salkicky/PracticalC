#include "words_dict.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    void *context = NULL;
    char *word = NULL;
    int counter = 0;
    
    context = word_dict_create_context();
    
    printf("ADD\n");
    word_dict_add(context, "apple", strlen("apple"));
    printf("ADD\n");
    word_dict_add(context, "orange", strlen("orange"));
    printf("ADD\n");
    word_dict_add(context, "orange", strlen("orange"));
    printf("ADD\n");
    word_dict_add(context, "test", strlen("test"));
    printf("ADD\n");
    word_dict_add(context, "orange", strlen("orange"));
    printf("ADD\n");
    word_dict_add(context, "apple", strlen("apple"));
    printf("GET\n");
    word_dict_get_a_word(context, &word, &counter);
    
    if (word != NULL) {
        printf("---word=%s----\n", word);
        printf("---counter=%d----\n", counter);
    } else {
        printf("NULL\n");
    }

    printf("DESTROY\n");
    word_dict_destroy_context(context);

    printf("end\n");
    return 0;
}
