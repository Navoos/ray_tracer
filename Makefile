SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
LFLAGS = -L ./minilibx -lmlx -framework OpenGL -framework Appkit -I.
NAME = tracer

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ) $(NAME)

run : $(NAME)
	@./tracer
