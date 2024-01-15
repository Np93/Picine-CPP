FILES	= main.cpp Bureaucrat.cpp Form.cpp

OBJS	= ${FILES:.cpp=.o}

NAME	= Bureaucrat

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -f
CXX		= c++

$(NAME): $(OBJS)
		$(CXX) ${CXXFLAGS} -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
