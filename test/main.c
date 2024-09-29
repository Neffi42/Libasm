#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

unsigned long ft_strlen(const char* s);
int ft_strcmp(const char* s1, const char* s2);
char *ft_strcpy(char* restrict dst, const char* restrict src);
ssize_t ft_write(int fd, const void* buf, size_t count);
ssize_t ft_read(int fd, void* buf, size_t count);
char *ft_strdup(const char *s);

void print_section_separator(const char* section_name) {
    printf("\n==== %s ====\n", section_name);
}

void test_ft_strlen() {
    print_section_separator("ft_strlen");

    char* s1 = "This is a test";
    printf("Test string: '%s'\n", s1);
    printf("Expected strlen: %lu\n", strlen(s1));
    printf("ft_strlen: %lu\n", ft_strlen(s1));

    char* s2 = NULL;
    printf("\nTest string: NULL\n");
    printf("Expected behavior: segmentation fault\n");
    printf("ft_strlen: %lu (avoid crash due to null pointer)\n", ft_strlen(s2));
}

void test_ft_strcmp() {
    print_section_separator("ft_strcmp");

    char* s1 = "This is a test";
    char* s2 = "This is a test";
    printf("Test strings: '%s' and '%s'\n", s1, s2);
    printf("Expected strcmp: %d\n", strcmp(s1, s2));
    printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));

    char* s3 = "This is a test";
    char* s4 = "This is not a test";
    printf("\nTest strings: '%s' and '%s'\n", s3, s4);
    printf("Expected strcmp: %d\n", strcmp(s3, s4));
    printf("ft_strcmp: %d\n", ft_strcmp(s3, s4));

    char* s5 = NULL;
    printf("\nTest strings: NULL and NULL\n");
    printf("Expected behavior: segmentation fault\n");
    printf("ft_strcmp: %d (avoid crash due to null pointer)\n", ft_strcmp(s5, s5));
}

void test_ft_strcpy() {
    print_section_separator("ft_strcpy");

    char* s1 = "123456789";
    char s2[10] = {0};
    printf("Test strings: '%s' and destination buffer (empty)\n", s1);
    printf("Expected strcpy: '%s'\n", strcpy(s2, s1));
    printf("ft_strcpy: '%s'\n", ft_strcpy(s2, s1));

    char* s3 = NULL;
    char* s4 = NULL;
    printf("\nTest strings: NULL and NULL\n");
    printf("Expected behavior: segmentation fault\n");
    printf("ft_strcpy: %s (avoid crash due to null pointer)\n", ft_strcpy(s3, s4));
}

void test_ft_write() {
    print_section_separator("ft_write");

    char* s1 = "This is a test";
    printf("Test string: '%s'\n", s1);
    ssize_t n1 = write(1, s1, ft_strlen(s1));
    write(1, "\n", 1);
    ssize_t n2 = ft_write(1, s1, ft_strlen(s1));
    ft_write(1, "\n", 1);
    printf("Expected write: %ld\n", n1);
    printf("ft_write: %ld\n", n2);

    printf("\nTesting invalid file descriptor (-1):\n");
    char* s2 = "This is an error";
    n1 = write(-1, s2, ft_strlen(s2));
    if (n1 == -1) {
        printf("write failed, errno: %d\n", errno);
        perror("write error");
    }
    n2 = ft_write(-1, s2, ft_strlen(s2));
    if (n2 == -1) {
        printf("ft_write failed, errno: %d\n", errno);
        perror("ft_write error");
    }
}

void test_ft_read() {
    print_section_separator("ft_read");

    char buf[100];
    printf("Reading from stdin (enter some text):\n");
    ssize_t n1 = read(0, buf, 100);
    buf[n1] = '\0';
    printf("Data read by read: '%s' (bytes read: %ld)\n", buf, n1);

    ssize_t n2 = ft_read(0, buf, 100);
    buf[n2] = '\0';
    printf("Data read by ft_read: '%s' (bytes read: %ld)\n", buf, n2);

    char* file_name = "./Makefile";
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file '%s'\n", file_name);
        perror("open error");
    } else {
        char file_buf[50];
        ssize_t file_read = read(fd, file_buf, 50);
        file_buf[file_read] = '\0';
        printf("\nData read by read from '%s': '%s' (bytes read: %ld)\n", file_name, file_buf, file_read);

        lseek(fd, 0, SEEK_SET);
        ssize_t ft_file_read = ft_read(fd, file_buf, 50);
        file_buf[ft_file_read] = '\0';
        printf("Data read by ft_read from '%s': '%s' (bytes read: %ld)\n", file_name, file_buf, ft_file_read);

        close(fd);
    }

    printf("\nTesting invalid file descriptor (-1):\n");
    ssize_t n3 = read(-1, buf, 100);
    if (n3 == -1) {
        printf("read failed, errno: %d\n", errno);
        perror("read error");
    }
    ssize_t n4 = ft_read(-1, buf, 100);
    if (n4 == -1) {
        printf("ft_read failed, errno: %d\n", errno);
        perror("ft_read error");
    }
}

void test_ft_strdup() {
	print_section_separator("ft_strdup");

    char* s1 = "Hello, world!";
    char* dup1 = ft_strdup(s1);
    printf("Original: '%s'\n", s1);
    printf("Duplicated (ft_strdup): '%s'\n", dup1);
	free(dup1);
	dup1 = strdup(s1);
    printf("Expected: '%s'\n", dup1);
    free(dup1);

    // char* s2 = "";
    // char* dup2 = ft_strdup(s2);
    // printf("\nOriginal: '%s'\n", s2);
    // printf("Duplicated (ft_strdup): '%s'\n", dup2);
    // printf("Expected: '%s'\n", strdup(s2));
    // free(dup2);

    // char* dup3 = ft_strdup(NULL);
    // printf("\nOriginal: NULL\n");
    // if (dup3 == NULL) {
    //     printf("Duplicated (ft_strdup): NULL (Expected behavior for NULL input)\n");
    // } else {
    //     printf("Duplicated (ft_strdup): %s (Unexpected behavior)\n", dup3);
    //     free(dup3);
    // }

    // char* s3 = "Line1\nLine2\tSpecialChar\x01";
    // char* dup4 = ft_strdup(s3);
    // printf("\nOriginal with special chars: '%s'\n", s3);
    // printf("Duplicated (ft_strdup): '%s'\n", dup4);
    // free(dup4);

    // char* large_s = (char*)malloc(1000001);
    // if (large_s) {
    //     memset(large_s, 'A', 1000000);
    //     large_s[1000000] = '\0';
    //     char* large_dup = ft_strdup(large_s);
    //     printf("\nOriginal large string: first 10 chars '%.*s'...\n", 10, large_s);
    //     printf("Duplicated large string (ft_strdup): first 10 chars '%.*s'...\n", 10, large_dup);
    //     free(large_s);
    //     free(large_dup);
    // }
}

int main() {
    // test_ft_strlen();
    // test_ft_strcmp();
    // test_ft_strcpy();
    // test_ft_write();
    // test_ft_read();
	test_ft_strdup();

    return 0;
}
