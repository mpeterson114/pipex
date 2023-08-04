ORANGE =		\033[38;5;209m
CYAN =			\033[0;96m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
RED =			\033[0;91m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = ./srcs/pipex.c \
		./srcs/utils.c \
		./string_fxns/ft_split.c \
		./string_fxns/ft_strjoin.c \
		./string_fxns/ft_strncmp.c \
		./string_fxns/ft_putstr_fd.c \

BONUS_SRCS = ./bonus_srcs/files.c \
			./bonus_srcs/here_doc.c \
			./bonus_srcs/pipex_bonus.c \
			./bonus_srcs/child_bonus.c \
			./bonus_srcs/utils_bonus.c \
			./bonus_srcs/free_bonus.c \
			./string_fxns/ft_putstr_fd.c \
			./string_fxns/ft_split.c \
			./string_fxns/ft_strjoin.c \
			./string_fxns/ft_strncmp.c \
			./gnl/get_next_line_utils.c \
			./gnl/get_next_line.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address  -O
REMOVE = rm -f

%.o: %.c 
	@echo "$(YELLOW) Compiling	$(WHITE)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\n$(GREEN)Objects and executables created successfully ✅\n"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(NAME_BONUS)
	@echo "\n$(GREEN)Bonus objects and executables created successfully 🏁\n"


clean:
	@$(REMOVE) $(OBJS) $(OBJS_BONUS)
	@echo "\n$(ORANGE)Objects cleaned successfully ✅\n"

fclean:
	@$(REMOVE) $(OBJS) $(OBJS_BONUS)
	@$(REMOVE) $(NAME) $(NAME_BONUS)
	@echo "\n$(PURPLE)Objects and executables deleted successfully ✅\n"

re:	fclean all

rebonus: fclean $(NAME_BONUS)

.PHONY: all clean fclean re rebonus