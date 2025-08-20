NAME 	=	Weapon
CC 		=	c++

HEADER 	=	Account.hpp

CFLAGS 	= 	 -Wall -Wextra -Werror -std=c++98

SRC 	=	HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp \
			main.cpp \


OBJ 	= 	${SRC:.cpp=.o}

all: ${NAME}


${NAME} : ${OBJ}
	 ${CC} ${OBJ} $(CFLAGS) -o ${NAME}

%.o : %.cpp $(HumanA.hpp) $(HumanB.hpp)
	 ${CC} $(CFLAGS)  -c $< -o $@
	
clean :
	@rm -f ${OBJ}

re: fclean all

fclean : clean
	@rm -f ${NAME}
	
.PHONY: all clean fclean re