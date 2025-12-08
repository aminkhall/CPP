NAME 	=	Identify
CC 		=	c++

HEADER 	=	Base.hpp \
			A.hpp \
			B.hpp \
			C.hpp \

CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98

SRC 	=	Base.cpp \
			main.cpp \

OBJ 	= 	${SRC:.cpp=.o}

all: ${NAME}

${NAME} : ${OBJ}
	 ${CC} ${OBJ} $(CFLAGS) -o ${NAME}

%.o : %.cpp $(HEADER)
	 ${CC} $(CFLAGS)  -c $< -o $@
	
clean :
	@rm -f ${OBJ}

re: fclean all

fclean : clean
	@rm -f ${NAME}
	
.PHONY: all clean fclean re