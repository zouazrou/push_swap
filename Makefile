CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix algorithms/, )

NAME = push_swap
all :	$(NAME)

$(NAME) :
	$(CC) -g ./operations/*.c ./lib/*.c ./algorithms/*.c ./errors_wkda/*.c ./push_swap_utils/*.c -o $@
# clean :
# rm push_swap
# re : clean all

.PHONY : clean all re
