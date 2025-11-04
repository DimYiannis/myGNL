CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=n
NAME = getnextline.a

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

%.o: %.c  get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
