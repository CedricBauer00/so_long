CFLAGS	= -Wall -Wextra -Werror #-g3 #-I./libft #-L./libft -lft

RM = rm -f
CC = cc

# COLOUR_GREEN = \033[0;32m
# COLOUR_RED = \033[0;31m
# COLOUR_END = \033[0m

NAME	= ft_printf.a

LIBFT_SOURCES =	./libft/ft_isascii.c \
			./libft/ft_atoi.c \
			./libft/ft_bzero.c \
			./libft/ft_isalnum.c \
			./libft/ft_isdigit.c \
			./libft/ft_isprint.c \
			./libft/ft_memchr.c \
			./libft/ft_memcmp.c \
			./libft/ft_memcpy.c \
			./libft/ft_memmove.c \
			./libft/ft_memset.c \
			./libft/ft_isalpha.c \
			./libft/ft_strchr.c \
			./libft/ft_strdup.c \
			./libft/ft_strlcat.c \
			./libft/ft_strlcpy.c \
			./libft/ft_strlen.c \
			./libft/ft_strncmp.c \
			./libft/ft_strnstr.c \
			./libft/ft_strrchr.c \
			./libft/ft_tolower.c \
			./libft/ft_toupper.c \
			./libft/ft_calloc.c \
			./libft/ft_strdup.c \
			./libft/ft_substr.c \
			./libft/ft_strjoin.c \
			./libft/ft_strtrim.c \
			./libft/ft_putchar_fd.c \
			./libft/ft_putstr_fd.c \
			./libft/ft_putnbr_fd.c \
			./libft/ft_putendl_fd.c \
			./libft/ft_striteri.c \
			./libft/ft_strmapi.c \
			./libft/ft_itoa.c \
			./libft/ft_split.c

PRINTF_SOURCES =	ft_printf.c \
			ft_puthex_fd.c \
			ft_puthexupcase_fd.c \
			ft_putpad_fd.c \
			ft_putun_fd.c \
			ft_rvputstr_fd.c \
			ft_rvputnbr_fd.c \
			ft_rvputchar_fd.c


SOURCES = ${LIBFT_SOURCES} ${PRINTF_SOURCES}

OBJECTS	= ${SOURCES:.c=.o}

all: ${NAME}

%.o : %.c
	$(CC) ${CFLAGS} -c $< -o $@ ${INCLUDE}

${NAME}: ${OBJECTS}
	@ar rcs ${NAME} ${OBJECTS}
	@echo "$(COLOUR_GREEN)Printf compiled successfully!$(COLOUR_END)"

clean:
	${RM} ${OBJECTS} 
	@echo "$(COLOUR_RED)Objects cleaned successfully!$(COLOUR_END)"

fclean: clean
	${RM} ${NAME}
	@echo "$(COLOUR_RED)Printf cleaned successfully!$(COLOUR_END)"

re: fclean all

debug: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o debug
