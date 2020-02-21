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
RUNNER1	= make re -C /Users/rvegas-j/Desktop/GitHub/Printf/pft_2019
all:
			${CC} ${OBJS}
			${CCTWO}
			${NORM}
			${CLEAN}
			${CLEAR}
testp:
			${RUNNER1}
			cd /Users/rvegas-j/Desktop/GitHub/Printf/pft_2019 && ./test p

tests:
			${RUNNER1}
			cd /Users/rvegas-j/Desktop/GitHub/Printf/pft_2019 && ./test s

testc:
			${RUNNER1}
			cd /Users/rvegas-j/Desktop/GitHub/Printf/pft_2019 && ./test c
$(NAME):
			${CC} ${OBJS} ${CCTWO}
fclean:		clean
			${RM} ${NAME}
clean:
			${RM} *.o
re:			fclean all
.PHONY:		all clean testp tests testc  fclean re