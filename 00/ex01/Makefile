CC = g++ 

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Contact.cpp PhoneBook.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)
NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all
