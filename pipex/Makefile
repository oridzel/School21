NAME			=	libpipex.a

SRC_DIR			=	.
OBJ_DIR			=	./.obj

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-I.

C_FILES			=	$(wildcard $(SRC_DIR)/*.c)
H_FILES			=	./pipex.h
O_FILES			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))

all: $(NAME)

$(NAME): $(O_FILES)
	@printf "Creating archive $(NAME)\n"
	@ar rcs $(NAME) $?
	@printf "Creating binary\n"
	@$(CC) $(CFLAGS) -o pipex $(O_FILES) -L. -lpipex

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf "Making object $<\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) pipex

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(O_FILES)
.PHONY:	all clean fclean re
