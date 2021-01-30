
FLAGS = -Wall -Werror -Wextra -I. -c

LIB = ar rcs

NAME = libft.a

HEADER = libft.h

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_split.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_isascii.c  \
	ft_isprint.c \
	ft_strmapi.c \
	ft_putendl_fd.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_memmove.c 


SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstclear.c \
			ft_lstmap.c


OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(FLAGS) $(SRC)

$(OBJ_BONUS): $(SRC_BONUS)
	gcc $(FLAGS) $(SRC_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	$(LIB) $(NAME) $(OBJ_BONUS)

.PHONY: clean fclean all re bonus
