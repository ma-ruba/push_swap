NAME = push_swap

SRCS = srcs/push_swap/check.c srcs/push_swap/clean.c srcs/push_swap/push_swap.c \
		srcs/push_swap/push.c srcs/push_swap/quick_sort.c srcs/push_swap/reverse_rotate.c \
		srcs/push_swap/rotate.c srcs/push_swap/sort.c srcs/push_swap/sort2.c \
		srcs/push_swap/stack.c srcs/push_swap/swap.c srcs/push_swap/print_stack.c
OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a
INC = -I ./includes
LIBLINK = -L ./libft -lft
LIBINC = -I ./libft/includes

all: $(NAME) 

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(NAME): libft $(OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
	@echo "OK!"

rmlib:
	@echo "Deleting libft object files and libft.a..."
	@make fclean -C ./libft
	@echo "OK!"

clean: rmlib
	@echo "Deleting push_swap object files..."
	@rm -rf $(OBJ)
	@echo "OK!"

fclean: clean
	@echo "Deleting push_swap..."
	@rm -rf $(NAME)
	@echo "OK!"

re: fclean all
