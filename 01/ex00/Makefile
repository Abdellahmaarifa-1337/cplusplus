CC = g++ 

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)
NAME = zombie

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all
