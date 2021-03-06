/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:23:17 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 16:15:58 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		dispatcher1(const char *f, int i, va_list ap, t_flag flag)
{
	int a;

	a = 0;
	if (f[i] == 'd' || f[i] == 'i')
		a = ft_print_number(ap, flag);
	else if (f[i] == 'o')
		a = ft_print_octal(ap, flag);
	else if (f[i] == 'u')
		a = ft_print_unsign(ap, flag);
	else if (f[i] == 'x')
		a = ft_print_uhex(ap, flag);
	else if (f[i] == 'X')
		a = ft_print_uhexmaj(ap, flag);
	else
		a = -100;
	return (a);
}

int				dispatcher(va_list ap, int i, const char *f)
{
	int		t;
	t_flag	flag;
	int		a;

	a = 0;
	t = i;
	capture_the_flag(f, t, &flag);
	if (f[i] == '\0')
		return (-1);
	if (check_error(f, i) == -1)
		return (-1);
	increment(f, &i);
	if (f[i] == 'c')
		return (ft_print_char(ap, flag));
	else if (f[i] == 's')
		return (ft_print_string(ap, flag));
	else if (f[i] == 'p')
		return (ft_print_hex(flag, ap));
	if ((a = dispatcher1(f, i, ap, flag)) != -100)
		return (a);
	if (f[i] == 'f')
		return (ft_print_float(ap, flag));
	else if (f[i] == '%')
		return (ft_print_percent(flag, f, t));
	return (-1);
}
