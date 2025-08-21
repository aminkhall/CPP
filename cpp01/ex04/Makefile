NAME 	=	Test
CC 		=	c++

HEADER 	=	Account.hpp

CFLAGS 	= 	 -Wall -Wextra -Werror -std=c++98

SRC 	=	main.cpp \


OBJ 	= 	${SRC:.cpp=.o}

all: ${NAME}


${NAME} : ${OBJ}
	 ${CC} ${OBJ} $(CFLAGS) -o ${NAME}

%.o : %.cpp
	 ${CC} $(CFLAGS)  -c $< -o $@
	
clean :
	@rm -f ${OBJ}

re: fclean all

fclean : clean
	@rm -f ${NAME}
	
.PHONY: all clean fclean re