RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
EOC:="\033[0;0m"
YELLOW:="\033[1;33m"
ORANGE:="\033[0;33m"

NAME=philo

PROGRAMME_FILES = ./ft_atoi.c \
				  ./init.c \
				  ./la_utils.c \
				  ./main.c \
				  ./les_threads.c \
				  ./routines.c \

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -O3 -pthread

OBJS = ${PROGRAMME_FILES:.c=.o}
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		 ${CC} ${CFLAGS} ${OBJS} -o $(NAME)
		 echo $(GREEN) "COMPILED SUCCESSFLLY..." $(EOC)
	
all: $(NAME)

clean: 
	   rm -f $(OBJS)
	   echo $(YELLOW) "Cleaning OBJS...🧹" $(EOC)

fclean:
		rm -f $(NAME)
		rm -f $(OBJS)
		echo $(ORANGE) "Cleaning NAME & OBJS...🧹" $(EOC)

re: fclean all
.PHONY: all clean fclean re