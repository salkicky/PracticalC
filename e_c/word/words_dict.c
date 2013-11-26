#include "words_dict.h"

struct word_dict_tag {
	char *word;
	int count;
	struct word_dict_tag *np;
};

static word_dict_tag *headp;





