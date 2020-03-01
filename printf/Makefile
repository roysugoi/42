COMPI	= gcc -c -Wall -Wextra -Werror
OBJS	= ft_printf_c.c ft_printf_i1.c ft_printf_i2.c ft_printf_p1.c ft_printf_p2.c  ft_printf_pc.c ft_printf_s.c ft_printf_tools1.c ft_printf_tools2.c ft_printf_tools3.c ft_printf_tools4.c ft_printf_u1.c ft_printf_u2.c ft_printf_x1.c ft_printf_x2.c ft_printf_flags.c ft_printf.c
ARCHI	= ar rc libftprintf.a *.o
all:
			${COMPI} ${OBJS}
			${ARCHI}
fclean:		clean
			${RM} ${NAME}
clean:
			${RM} *.o
re:			fclean all
.PHONY:		all fclean clean re