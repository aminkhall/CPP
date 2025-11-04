NAME 	=	Interface 
CC 		=	c++

HEADER 	=	AMateria.hpp \
			Character.hpp \
			Cure.hpp \
			Ice.hpp \
			ICharacter.hpp \
			IMateriaSource.hpp \
			MateriaSource.hpp \

CFLAGS 	= 	 -fsanitize=address -g -Wall -Wextra -Werror -std=c++98

SRC 	=	AMateria.cpp \
			Character.cpp \
			Cure.cpp \
			Ice.cpp \
			ICharacter.cpp \
			IMateriaSource.cpp \
			main.cpp \
			MateriaSource.cpp \

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