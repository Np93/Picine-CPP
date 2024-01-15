FILES	= main.cpp

OBJS	= ${FILES:.cpp=.o}

NAME	= remplace

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

magic: fclean
		$(RM) *.replace

re:		fclean all

.PHONY:	all clean fclean re
