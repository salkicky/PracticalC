#include <stdio.h>

int main()
{
	char line[20];

	memset(line, "a", 4);
	printf("--%s\n", line);
	return 0;
}
