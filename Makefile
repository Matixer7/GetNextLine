NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)  $(TESTBIN)

fclean: clean
	rm -f $(NAME) $(TESTBIN)

re: fclean all

.PHONY: clean fclean