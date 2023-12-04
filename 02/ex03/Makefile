CC = g++

CFLAGS = -Wall -Werror -Wextra

NAME = fixed

SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp

OBJ = ${SRC:.cpp=.o}

.cpp.o :
	${CC} ${CFLAGS} -c $< -o $@

all: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${OBJ}:${SRC}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean fclean all re