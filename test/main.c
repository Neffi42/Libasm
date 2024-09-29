#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long ft_strlen(const char* s);
int ft_strcmp(const char *s1, const char *s2);

int main() {
	{
		printf("ft_strlen:\n");

		char* s1 = "This a test";
		printf("\tTest string: '%s'\n\tstrlen: %ld\n\tft_strlen: %ld\n", s1, strlen(s1), ft_strlen(s1));

		char* s2 = NULL;
		printf("\tTest string: '%s'\n\tstrlen: %s\n\tft_strlen: %ld\n", s2, "segmentation fault", ft_strlen(s2));
	}
	{
		printf("ft_strcmp:\n");

		char* s1 = "This a test";
		char* s2 = "This a test";
		printf("\tTest strings: '%s' '%s'\n\tstrcmp: %d\n\tft_strcmp: %d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

		char* s3 = "This not a test";
		char* s4 = "This a test";
		printf("\tTest strings: '%s' '%s'\n\tstrcmp: %d\n\tft_strcmp: %d\n", s3, s4, strcmp(s3, s4), ft_strcmp(s3, s4));

		char* s5 = "This a test";
		char* s6 = "This not a test";
		printf("\tTest strings: '%s' '%s'\n\tstrcmp: %d\n\tft_strcmp: %d\n", s5, s6, strcmp(s5, s6), ft_strcmp(s5, s6));

		char* s7 = NULL;
		printf("\tTest strings: '%s' '%s'\n\tstrcmp: %d\n\tft_strcmp: %d\n", s7, s7, strcmp(s7, s7), ft_strcmp(s7, s7));
	}
	return 0;
}
