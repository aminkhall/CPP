NAME 	=	Form 
CC 		=	c++

HEADER 	=	Bureaucrat.hpp \
			AForm.hpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.hpp \

CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98

SRC 	=	Bureaucrat.cpp \
			AForm.cpp \
			main.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \

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