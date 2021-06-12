NAME			=	libftprintf.a

SRC_DIR			=	./srcs
INC_DIR			=	./includes
OBJ_DIR			=	./.obj

LIBFT_DIR		=	./../libft
LIBFT_NAME		=	libft.a
LIBFT_OBJS		=	$(LIBFT_DIR)/.obj/*.o

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-I$(INC_DIR) -I.

C_FILES			=	$(wildcard $(SRC_DIR)/*.c)
H_FILES			=	$(wildcard $(INC_DIR)/*.h) libftprintf.h $(LIBFT_DIR)/libft.h
O_FILES			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))

all: libft $(NAME)

$(NAME): $(O_FILES) $(LIBFT_DIR)/$(LIBFT_NAME)
	@printf "Creating archive $(NAME)\n"
	@ar rcs $(NAME) $(O_FILES) $(LIBFT_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf "Making object $<\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

libft:
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) $(LIBFT_DIR)/$(LIBFT_NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(O_FILES)
.PHONY:	all clean fclean re dev libft