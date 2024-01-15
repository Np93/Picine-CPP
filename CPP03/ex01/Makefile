FILES	= main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS	= ${FILES:.cpp=.o}

NAME	= ScavTrap

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -f
CC		= clang++

$(NAME): $(OBJS)
		$(CC) ${FLAGS} -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
