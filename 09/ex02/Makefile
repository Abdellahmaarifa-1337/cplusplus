CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address
SRC = main.cpp PmergeMe.cpp
OBJ = ${SRC:.cpp=.o}
NAME = PmergeMe

.cpp.o:
	${CC} ${CFLAGS} -c $< -o $@

All : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${OBJ} : ${SRC}

clean:
	rm -rf ${OBJ}
fclean: clean
	rm -rf ${NAME}
re: clean fclean All

.PHONY: clean fclean re all