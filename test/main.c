#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	{
		printf("ft_strlen:\n");
		char* s1 = "This a test";
		printf("Test string: '%s'\nstrlen: %ld\nft_strlen: %ld\n", s1, strlen(s1), ft_strlen(s1));
	}
	return 0;
}
