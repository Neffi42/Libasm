#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

unsigned long ft_strlen(const char* s);
int ft_strcmp(const char* s1, const char* s2);
char *ft_strcpy(char* restrict dst, const char* restrict src);
ssize_t ft_write(int fd, const void* buf, size_t count);

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
	{
		printf("ft_strcpy:\n");

		char* s1 = "123456789";
		char s2[10] = {0};
		printf("\tTest strings: '%s' '%s'\n\tstrcpy: %s\n\tft_strcpy: %s\n", s1, s2, strcpy(s2, s1), ft_strcpy(s2, s1));

		char* s3 = NULL;
		char* s4 = NULL;
		printf("\tTest strings: '%s' '%s'\n\tstrcpy: %s\n\tft_strcpy: %s\n", s3, s4, "segmentation fault", ft_strcpy(s3, s4));
	}
	{
		printf("ft_write:\n");

		char* s1 = "This a test";
		printf("\tTest string: '%s'\n", s1);
		ssize_t n1 = write(1, s1, ft_strlen(s1));
		write(1, "\n", 1);
		ssize_t n2 = ft_write(1, s1, ft_strlen(s1));
		ft_write(1, "\n", 1);
		printf("\twrite: %ld\n\tft_write: %ld\n", n1, n2);

		char* s2 = "This an error";
		printf("\tTest string: '%s'\n", s2);
		n1 = write(1, s2, ft_strlen(s2));
		write(1, "\n", 1);
		n2 = ft_write(1, s2, ft_strlen(s2));
		ft_write(1, "\n", 1);
		printf("\twrite: %ld\n\tft_write: %ld\n", n1, n2);

		n1 = write(-1, s2, ft_strlen(s2));
		if (n1 == -1) {
      		printf("write failed, errno: %d\n", errno);
        	perror("write error");
    	}
		n2 = ft_write(-1, s2, ft_strlen(s2));
		printf("n2: %ld\n", n2);
		if (n2 == -1) {
			printf("ft_write failed, errno: %d\n", errno);
			perror("ft_write error");
		}
	}
	return 0;
}
