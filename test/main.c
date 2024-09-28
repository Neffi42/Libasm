#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long ft_strlen(const char* s);

int main() {
	{
		printf("ft_strlen:\n");

		char* s1 = "This a test";
		printf("\tTest string: '%s'\n\tstrlen: %ld\n\tft_strlen: %ld\n", s1, strlen(s1), ft_strlen(s1));

		char* s2 = NULL;
		printf("\tTest string: '%s'\n\tstrlen: %s\n\tft_strlen: %ld\n", s2, "segmentation fault", ft_strlen(s2));
	}
	return 0;
}
