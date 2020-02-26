/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 17:19:51 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [E - Tests with .].
	if (nb == count++)
		return(ac == 2 ? printf("%.0%") : ft_printf("%.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.0%") : ft_printf("%.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.1%") : ft_printf("%.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.2%") : ft_printf("%.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.10%") : ft_printf("%.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.0s", "") : ft_printf("%.0s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%.1s", "") : ft_printf("%.1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%.3s", "") : ft_printf("%.3s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%.0s", "Hello") : ft_printf("%.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.1s", "Hello") : ft_printf("%.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.2s", "Hello") : ft_printf("%.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.5s", "Hello") : ft_printf("%.5s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.6s", "Hello") : ft_printf("%.6s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.7s", "Hello") : ft_printf("%.7s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.s", 42) : ft_printf("%.s", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", 0) : ft_printf("%.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", 0) : ft_printf("%.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", 0) : ft_printf("%.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", 5) : ft_printf("%.0d", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", 5) : ft_printf("%.1d", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", 5) : ft_printf("%.2d", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", 42) : ft_printf("%.0d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", 42) : ft_printf("%.1d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", 42) : ft_printf("%.2d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3d", 42) : ft_printf("%.3d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10d", 42) : ft_printf("%.10d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6d", 100) : ft_printf("%.6d", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", -1) : ft_printf("%.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", -1) : ft_printf("%.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", -1) : ft_printf("%.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3d", -1) : ft_printf("%.3d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", -42) : ft_printf("%.0d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", -42) : ft_printf("%.1d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3d", -42) : ft_printf("%.3d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4d", -42) : ft_printf("%.4d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MAX) : ft_printf("%.20d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MAX + 1) : ft_printf("%.20d", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MIN) : ft_printf("%.20d", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MIN - 1) : ft_printf("%.20d", INT_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", 0) : ft_printf("%.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", 0) : ft_printf("%.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", 0) : ft_printf("%.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", 5) : ft_printf("%.0i", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", 5) : ft_printf("%.1i", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", 5) : ft_printf("%.2i", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", 42) : ft_printf("%.0i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", 42) : ft_printf("%.1i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", 42) : ft_printf("%.2i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3i", 42) : ft_printf("%.3i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10i", 42) : ft_printf("%.10i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6i", 100) : ft_printf("%.6i", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", -1) : ft_printf("%.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", -1) : ft_printf("%.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", -1) : ft_printf("%.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3i", -1) : ft_printf("%.3i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", -42) : ft_printf("%.0i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", -42) : ft_printf("%.1i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3i", -42) : ft_printf("%.3i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4i", -42) : ft_printf("%.4i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MAX) : ft_printf("%.20i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MAX + 1) : ft_printf("%.20i", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MIN) : ft_printf("%.20i", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MIN - 1) : ft_printf("%.20i", INT_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", 0) : ft_printf("%.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", 0) : ft_printf("%.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", 0) : ft_printf("%.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", 5) : ft_printf("%.0u", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", 5) : ft_printf("%.1u", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", 5) : ft_printf("%.2u", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", 42) : ft_printf("%.0u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", 42) : ft_printf("%.1u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", 42) : ft_printf("%.2u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3u", 42) : ft_printf("%.3u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10u", 42) : ft_printf("%.10u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6u", 100) : ft_printf("%.6u", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", -1) : ft_printf("%.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", -1) : ft_printf("%.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", -1) : ft_printf("%.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3u", -1) : ft_printf("%.3u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", -42) : ft_printf("%.0u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", -42) : ft_printf("%.1u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3u", -42) : ft_printf("%.3u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4u", -42) : ft_printf("%.4u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20u", UINT_MAX) : ft_printf("%.20u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20u", UINT_MAX + 1) : ft_printf("%.20u", UINT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", 0) : ft_printf("%.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", 0) : ft_printf("%.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", 0) : ft_printf("%.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", 5) : ft_printf("%.0x", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", 5) : ft_printf("%.1x", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", 5) : ft_printf("%.2x", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", 42) : ft_printf("%.0x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", 42) : ft_printf("%.1x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", 42) : ft_printf("%.2x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3x", 42) : ft_printf("%.3x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10x", 42) : ft_printf("%.10x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6x", 100) : ft_printf("%.6x", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", -1) : ft_printf("%.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", -1) : ft_printf("%.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", -1) : ft_printf("%.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3x", -1) : ft_printf("%.3x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", -42) : ft_printf("%.0x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", -42) : ft_printf("%.1x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3x", -42) : ft_printf("%.3x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4x", -42) : ft_printf("%.4x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20x", UINT_MAX) : ft_printf("%.20x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20x", UINT_MAX + 1) : ft_printf("%.20x", UINT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", 0) : ft_printf("%.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", 0) : ft_printf("%.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", 0) : ft_printf("%.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", 5) : ft_printf("%.0X", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", 5) : ft_printf("%.1X", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", 5) : ft_printf("%.2X", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", 42) : ft_printf("%.0X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", 42) : ft_printf("%.1X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", 42) : ft_printf("%.2X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3X", 42) : ft_printf("%.3X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10X", 42) : ft_printf("%.10X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6X", 100) : ft_printf("%.6X", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", -1) : ft_printf("%.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", -1) : ft_printf("%.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", -1) : ft_printf("%.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3X", -1) : ft_printf("%.3X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", -42) : ft_printf("%.0X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", -42) : ft_printf("%.1X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3X", -42) : ft_printf("%.3X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4X", -42) : ft_printf("%.4X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20X", UINT_MAX) : ft_printf("%.20X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20X", UINT_MAX + 1) : ft_printf("%.20X", UINT_MAX + 1));

	// [F - Tests with minimum field width and .].
return (0);
}
