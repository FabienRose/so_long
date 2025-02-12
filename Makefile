NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c map.c check_map.c check_map_utils.c set_tiles.c key_binds.c key_binds_utils.c cleanup.c
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT = libft/libft.a
MLX = minilibx_linux/libmlx.a

MLX_LIBS = -Lminilibx_linux -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Compiling SO_LONG..."
	@sleep 0.5
	@echo "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"
	@sleep 0.1
	@echo "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.....&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"
	@sleep 0.1
	@echo "&&*********&&*****&****&&*****/&&&...****&&&&&&&&&&&&&&&*****&&*****&***&*****#&&******&&&********&&"
	@sleep 0.1
	@echo "&#%....&%...&&...&&...&&...&&&&&&#...&%...&&&&&&&&&&&&#...%%&&%%...&%...&%...&&&&%%%&...&%&...%&...&"
	@sleep 0.1
	@echo "&&#....&#...&&...&&...&&&.....,&&#...&#...&&&&&&&&&&&&&%.....&&#...&%...&&...&&&&.......&&&...&&...&"
	@sleep 0.1
	@echo "&&&....&&...&&...&%...&&%&&&....&&...&&...&&&&&&&&&&&&%#%&&...&&&...........&&&%...%#...&&#...&%...&"
	@sleep 0.1
	@echo "&&&........&&&&........&......,&&....&.....&.........%#......&&&&%....&....&&&%#%........&%.......&&"
	@sleep 0.1
	@echo "&&&....&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#...&&&&&&"
	@sleep 0.1
	@echo "&&......&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.....&&&&&"
	@sleep 0.1
	@echo "&##&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&%#&&&&&&\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_LIBS)
	@echo "SO_LONG compiled."

# Rule to create object files in obj/ directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@

# Rule to create obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C libft clean
	@echo "SO_LONG object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "SO_LONG all cleaned."

re: fclean all

.PHONY: all clean fclean re
