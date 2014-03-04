#include "words_dict.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    void *context = NULL;
    char *word = NULL;
    int counter = 0;
    
    context = word_dict_create_context();
    
    word_dict_add(context, "apple", strlen("apple"));
    word_dict_add(context, "orange", strlen("orange"));
    word_dict_add(context, "test", strlen("test"));
    word_dict_add(context, "orange", strlen("orange"));
    word_dict_get_a_word(context, &word, &counter);
    
    if (word != NULL) {
        printf("---word=%s----\n", word);
        printf("---counter=%d----\n", counter);
    } else {
        printf("NULL\n");
    }

    word_dict_destroy_context(context);

    printf("end\n");
    return 0;
}
