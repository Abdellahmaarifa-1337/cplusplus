CC = g++ 

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = account

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all
