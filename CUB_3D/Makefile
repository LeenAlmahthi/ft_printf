CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -ILibft -Iget_next_line
MLX_FLAGS = -lmlx -lXext -lX11 -lm 
NAME = cub_3d
OBJDIR = obj

SRC = main.c ft_error_file.c fill_dir.c free.c read_line.c read_file_utils.c init_maps.c

LIBFT_SRC = $(shell cat src.txt)

ALL_SRC = $(SRC) $(LIBFT_SRC)

OBJ = $(ALL_SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# CC = cc

# CFLAGS = -Wall -Wextra -Werror -I. -ILibft -Iget_next_line
# MLX_FLAGS = -lmlx -lXext -lX11 -lm 
# NAME = cub_3d
# OBJDIR = obj

# SRC = main.c ft_error_file.c fill_dir.c free.c read_line.c read_file_utils.c init_maps.c

# LIBFT_SRC = $(shell cat src.txt)

# ALL_SRC = $(SRC) $(LIBFT_SRC)

# OBJ = $(ALL_SRC:%.c=$(OBJDIR)/%.o)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

# $(OBJDIR)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(MLX_FLAGS)  -c $< -o $@

# clean:
# 	rm -rf $(OBJDIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
