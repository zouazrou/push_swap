CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = $(addprefix pushswap/, push_swap.c utils.c another_utils.c) \
	   $(addprefix operations/, another_operations.c pop.c push.c reverse_rotate.c rotate.c swap.c) \
	   $(addprefix lib/, ft_atoi.c ft_isdigit.c ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c \
		ft_lstsecondtolast.c ft_lstsize.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strlcpy.c ft_strlen.c) \
	   $(addprefix errors_wkda/, error.c  utils.c) \
	   $(addprefix algorithms/, sort_tree_nbs.c  stack_sort_2.c  stack_sort.c)

SRCS_BNS = $(addprefix bonus/, \
	   Checker/checker_bonus.c \
	   $(addprefix errors_wkda/, error_bonus.c utils_bonus.c) \
	   $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \
	   $(addprefix hashMap/, HashMap_bonus.c) \
	   $(addprefix lib/, ft_atoi_bonus.c ft_lstclear_bonus.c ft_lstsecondtolast_bonus.c \
	   ft_putstr_fd_bonus.c ft_isdigit_bonus.c ft_lstdelone_bonus.c ft_lstsize_bonus.c \
	   ft_split_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_strlcpy_bonus.c \
	   ft_lstnew_bonus.c ft_strlen_bonus.c ft_strcmp_bonus.c) \
	   $(addprefix operations/, pop_bonus.c  push_bonus.c  reverse_rotate_bonus.c  rotate_bonus.c  swap_bonus.c))
OBJ = $(SRCS:.c=.o)

OBJ_BNS = $(SRCS_BNS:.c=.o)

NAME = push_swap

NAME_CHECKER = checker

all :	$(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bonus : $(NAME_CHECKER)

$(NAME_CHECKER) : $(OBJ_BNS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	@rm -rf $(OBJ) ; rm -rf $(OBJ_BNS)
fclean : clean
	@rm -rf $(NAME) ; rm -rf $(NAME_CHECKER)
re : fclean all

.PHONY : clean all re bonus
