LIB				=	libpushswap.a
BIN				=	push_swap

SRC_DIR			=	./src
INC_DIR			=	./includes
OBJ_DIR			=	./.obj

LIBFT_DIR		=	./libft
LIBFT_NAME		=	libft.a
LIBFT_OBJS		=	$(LIBFT_DIR)/.obj/*.o

CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
IFLAGS			=	$(addprefix -I,$(INC_DIR))

C_FILES			=	$(wildcard $(SRC_DIR)/*.c)
H_FILES			=	$(wildcard $(INC_DIR)/*.h)
O_FILES			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))

all: $(BIN)

$(BIN): libft $(LIB)
	@printf "Creating binary $(BIN)\n"
	@$(CC) $(CFLAGS) -o $@ $(O_FILES) -L. -lpushswap -fsanitize=address

$(LIB): $(O_FILES) $(LIBFT_DIR)/$(LIBFT_NAME)
	@printf "Creating archive $(LIB)\n"
	@ar rcs $(LIB) $? $(LIBFT_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf "Making object $<\n"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

libft:
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR) $(BIN)

fclean: clean
	@rm -rf $(LIB) $(LIBFT_DIR)/$(LIBFT_NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(O_FILES)
.PHONY:	all clean fclean re libft release
