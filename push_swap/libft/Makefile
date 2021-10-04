NAME		=	libft.a

INC_DIR		=	./../includes
OBJ_DIR		=	./.obj

HEADER_FILE =	$(INC_DIR)/libft.h

SRC			=	ft_strlen.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c \
				ft_isprint.c ft_isascii.c ft_isalnum.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strdup.c \
				ft_atoi.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
				ft_memcmp.c ft_memccpy.c ft_memchr.c ft_memmove.c ft_calloc.c \
				ft_strjoin.c ft_itoa.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_substr.c ft_strtrim.c ft_putendl_fd.c ft_strmapi.c ft_split.c
SRC_B		=	ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c \
				ft_lstlast.c ft_lstsize.c ft_lstdelone.c ft_lstmap.c

OBJ			=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
OBJ_B		=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_B))
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@printf "Creating archive $(NAME)\n"
	@ar rcs $(NAME) $?

$(OBJ_DIR)/%.o: %.c $(HEADER_FILE)
	@mkdir -p $(OBJ_DIR)
	@printf "Making object $<\n"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

bonus:
	make OBJ="$(OBJ_B)" all

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY:	all clean fclean re bonus