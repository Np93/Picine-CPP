FILES	= megaphone.cpp

OBJS	= ${FILES:.cpp=.o}

NAME	= megaphone

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

test:			$(NAME)
				./megaphone "shhhhh... I think the students are asleep..."
				./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
				./megaphone

.PHONY:	all clean fclean re
