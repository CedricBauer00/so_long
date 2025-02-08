CFLAGS = -Wall -Wextra -Werror 

MLXFLAGS = -L./MLX42/build/ -lmlx42 -lglfw -ldl -lm

RM = rm -f
CC = cc

NAME = so_long

LIBFT_DIR = libft

PRINTF_DIR = printf

GET_NEXT_LINE_DIR = get_next_line

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF = $(PRINTF_DIR)/ft_printf.a

GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

SOURCES = sl_main.c \
		sl_ck_input.c \
		sl_ck_input2.c \
		sl_ck_input3.c \
		sl_cr_map.c \
		

OBJECTS := $(SOURCES:.c=.o)

all: $(MLX) $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(OBJECTS) -o $(NAME)
	@echo "Programm is playable!"

$(MLX): $(MLX_DIR)
	@echo "Making..."
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4
	@echo "...finished"

$(MLX_DIR):
	@git clone https://github.com/codam-coding-college/MLX42.git $@

$(LIBFT): $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(PRINTF): $(PRINTF_DIR)
	@$(MAKE) -C $(PRINTF_DIR) --silent

$(GET_NEXT_LINE): $(GET_NEXT_LINE_DIR)
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) --silent

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(PRINTF_DIR) clean --silent
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean --silent
	@$(RM) $(OBJECTS)
	@echo "Programm cleaned successfully!"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(PRINTF)
	@$(RM) $(GET_NEXT_LINE)
	@$(RM) $(NAME)
	@echo "Programm cleaned successfully!"

re: fclean all

degub: $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o debug