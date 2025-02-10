NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_strlen.c ft_strncpy.c ft_putchar.c ft_strcmp.c ft_strncmp.c ft_tolower.c ft_toupper.c \
      ft_strncat.c ft_strcat.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
      ft_atoi.c ft_strstr.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strdup.c \
      ft_calloc.c ft_memchr.c ft_strlcat.c ft_strlcpy.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
      ft_itoa.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memcmp.c \
	  ft_strcpy.c ft_strchr.c ft_strrchr.c ft_memcmp.c ft_toupper.c ft_printf.c print_param.c ft_lstadd_back.c \
	  ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	  get_next_line.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling LIBFT...\n"
	@echo "               (((/,,.           *((((,,,   ,(((,,,            .(((((((((,,,                         "
	@sleep 0.1
	@echo "               (((*,,                       ,(((,,,           *(((,,,         (((*,,.               "
	@sleep 0.1
	@echo "               (((*,,          ((((((*,,    ,(((,(((((,,,  (((((((((((,,,  ((((((((((/,,.           "
	@sleep 0.1
	@echo "               (((*,,             (((*,,    ,((((,,,((((*,,   (((/,,.      ///(((((((*,,.           "
	@sleep 0.1
	@echo "               (((*,,             (((*,,    ,(((,,,  *(((,,,  (((/,,.         (((,,,                "
	@sleep 0.1
	@echo "               (((*,,             (((*,,    ,(((,,,  .(((,,,  (((/,,.        *(((,,,                "
	@sleep 0.1
	@echo "               (((*,,             (((*,,    ,(((/,,. (((*,,.  (((/,,.        ,(((,,,                "
	@sleep 0.1
	@echo "               ((((((((((((,,, (((((((((*,,.,((,(((((((,,,    (((/,,.         /((((((((,,,          \n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "LIBFT compiled."

# Rule to compile object files into obj/ directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

# Rule to create obj/ directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "LIBFT object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "LIBFT cleaned."

re: fclean all

.PHONY: all clean fclean re bonus