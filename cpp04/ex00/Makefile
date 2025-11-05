NAME 	=	Polymorphism
CC 		=	c++

HEADER 	=	Dog.hpp \
			Cat.hpp \
			Animal.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \

CFLAGS 	= 	 -Wall -Wextra -Werror -std=c++98

SRC 	=	main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \

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