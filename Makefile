CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix pushswap/, push_swap.c utils.c another_utils.c) \
	   $(addprefix operations/, another_operations.c pop.c push.c reverse_rotate.c rotate.c swap.c) \
	   $(addprefix lib/, ft_atoi.c ft_isdigit.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c \
		ft_lstsecondtolast.c ft_lstsize_bonus.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strlcpy.c ft_strlen.c) \
	   $(addprefix errors_wkda/, error.c  utils.c) \
	   $(addprefix algorithms/, sort_tree_nbs.c  stack_sort_2.c  stack_sort.c)

OBJ = $(SRCS:.c=.o)

NAME = push_swap

all :	$(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# $(CC) -g ./operations/*.c ./lib/*.c ./algorithms/*.c ./errors_wkda/*.c ./pushswap/*.c -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : clean all re
