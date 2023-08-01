ORANGE =		\033[38;5;209m
CYAN =			\033[0;96m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
RED =			\033[0;91m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = pipex

SRCS = ./srcs/pipex.c \
		./srcs/utils.c \
		./string_fxns/ft_split.c \
		./string_fxns/ft_strjoin.c \
		./string_fxns/ft_strncmp.c \
		./string_fxns/ft_putstr_fd.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address  -O
REMOVE = rm -f

%.o: %.c 
	@echo "$(YELLOW) Compiling	$(WHITE)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\n$(GREEN)Objects and executables created successfully ✅\n"

clean:
	@$(REMOVE) $(OBJS)
	@echo "\n$(ORANGE)Objects cleaned successfully ✅\n"

fclean:
	@$(REMOVE) $(OBJS)
	@$(REMOVE) $(NAME)
	@echo "\n$(PURPLE)Objects and executables deleted successfully ✅\n"

re:	fclean all

.PHONY: all clean fclean re