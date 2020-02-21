COMPI	= gcc -c -Wall -Wextra -Werror *.c
ARCHI	= ar rc libftprintf.a *.o
CLEAN	= rm -f *.o
CLEAR	= clear
NORMI	= norminette *.c
all:
			${COMPI}
			${ARCHI}
			${CLEAN}
			${CLEAR}
			${NORMI}
fclean:		clean
			${RM} ${NAME}
clean:
			${RM} *.o
re:			fclean all
.PHONY:		all fclean clean re