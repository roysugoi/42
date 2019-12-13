/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:04:43 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/12/12 20:21:39 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s = "Rodrigo";
int		i = 42;


void	magenta ()
{
  printf("\033[1;35m");
}

void	reset ()
{
  printf("\033[0m");
}

void	title1 ()
{
	magenta();
	printf("===========================================");
	printf("\n================= Results =================\n");
	printf("===========================================");
	reset();
	printf("\n\n");
}

void	title2 ()
{
	ft_printf("\n\n\n");
	magenta();
	printf("===========================================");
	printf("\n============= Printf behaviour ============\n");
	printf("===========================================");
	reset();
	printf("\n\n");
}

int		sresults()
{
	magenta();printf("--------------- *s = Rodrigo --------------\n\n");

	magenta();printf("%%-12s:\n");reset();
	printf("%-12s.\n\n", s);
	
	magenta();printf("%%-0.12s:\n");reset();
	printf("%-.12s.\n\n", s);

	magenta();printf("%%12s:\n");reset();
	printf("%12s.\n\n", s);

	magenta();printf("%%.2s:\n");reset();
	printf("%.2s.\n\n", s);

	magenta();printf("%%.*s, 2:\n");reset();
	printf("%.*s.\n\n", 2, s);

	magenta();printf("%%12.4s:\n");reset();
	printf("%12.4s.\n\n", s);

	magenta();printf("%%*.*s, 12, 4:\n");reset();
	printf("%*.*s.\n\n", 12, 4, s);

	magenta();printf("%%*.*s, 4, 12:\n");reset();
	printf("%*.*s.\n\n", 4, 12, s);

	magenta();printf("%%-*.*s., 4, 12, s:\n");reset();
	printf("%-*.*s.\n\n", 4, 12, s);

	magenta();printf("%%- Flag:\n");reset();
	printf("-%10s-.\n", s);
	printf("-%-10s-.\n", s);
	
	ft_printf("\n\n\n", s);
	return (0);
}

int		main(void)
{
	int x = 1;	//Muestra behaviour de "s", 1 = Activado.
	
	title1();
	ft_printf("Hola %s\n", s);

	if (x == 1)
	{
		title2();
		sresults(s);
	}
	return (0);
}
