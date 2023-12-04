CC = g++ 

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
NAME = megaphone

all: $(NAME)

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all
