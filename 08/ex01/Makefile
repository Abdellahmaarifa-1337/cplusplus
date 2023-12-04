CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Span.cpp
OBJ = ${SRC:.cpp=.o}
NAME = template

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

run: fclean All clean
	clear &&  echo "-------------------------------------\n" && ./template

.PHONY: clean fclean re all