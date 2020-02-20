SRC_DIR = SRC_DIR
INCLUDES=./
NAME	= libftprintf.a
OBJS	= *.c
CC		= gcc -c -Wall -Wextra -Werror
CCTWO	= ar rc libftprintf.a *.o
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
CLEAR	= clear
CLEAN	= rm -f *.o
NORM	= norminette *.c
all:
			${CC} ${OBJS}
			${CCTWO}
			${CLEAN}
			${CLEAR}
			${NORM}
$(NAME):
			${CC} ${OBJS} ${CCTWO}
fclean:		clean
			${RM} ${NAME}
clean:
			${RM} *.o
re:			fclean all
.PHONY:		all clean fclean re