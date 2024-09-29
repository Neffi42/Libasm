NAME        = libasm.a
SRC_DIR     = src
OBJ_DIR     = obj
SRC         = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s
OBJ         = $(patsubst %.s, $(OBJ_DIR)/%.o, $(SRC))
BONUS_SRC   = $(SRC) $(addprefix bonus/, )
BONUS_OBJ   = $(patsubst %.s, $(OBJ_DIR)/%.o, $(BONUS_SRC))
TEST_SRC    = $(addprefix test/, main.c)
TEST_PRGM 	= test_program
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3 -z noexecstack
NASM        = nasm
NASM_FLAGS  = -f elf64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(NASM) $(NASM_FLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(TEST_PRGM)

re: fclean all

bonus: fclean $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lasm -o $(TEST_PRGM)

.PHONY: all clean fclean re test
