NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_FILES =	ft_atoi.c ft_atoi_e.c ft_atoi_base_e.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcmp.c \
		ft_strncmp.c ft_bzero.c ft_calloc.c ft_memchr.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c ft_itoa.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strmapi.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \

BONUS_SRC =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
		ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		
OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADER_FILE = libft.h

all: $(NAME)
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^
%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@
bonus: $(OBJ_FILES) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ_FILES) $(BONUS_OBJ)
clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

