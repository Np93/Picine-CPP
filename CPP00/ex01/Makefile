FILES	= main.cpp PhoneBook.cpp Contact.cpp 

OBJS	= ${FILES:.cpp=.o}

NAME	= PhoneBook

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
