/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:43:38 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:47:48 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	increment_error1(const char *f, int *i, int j)
{
	if (f[j] == 'c' || f[j] == 's' || f[j] == 'p'
			|| f[j] == 'd' || f[j] == 'i' || f[j] == 'o' || f[j] == 'L'
			|| f[j] == 'u' || f[j] == 'x' || f[j] == 'X' || f[j] == 'l'
			|| f[j] == 'f' || f[j] == '%' || f[j] == 'h')
		(*i)++;
	if ((f[j] >= 58 || (f[j] >= 33 && f[j] <= 47))
			&& f[j] != 'c' && f[j] != 's' && f[j] != 'p'
			&& f[j] != 'd' && f[j] != 'i' && f[j] != 'o' && f[j] != 'u'
			&& f[j] != 'x' && f[j] != 'X' && f[j] != 'f' && f[j] != '%'
			&& f[j] != 'h' && f[j] != 'l' && f[j] != 'L')
		return (-1);
	return (0);
}

static void	give_b_the_value(const char *f, int t, int *b)
{
	if (*b == -5)
		if (flag_space_neg_nb_error(f, t) != 0)
			*b = -flag_space_neg_nb_error(f, t);
}

static void	starter(int *t, int *j, int *i)
{
	*j = *i;
	*t = *i;
}

void		increment(const char *format, int *i)
{
	while (format[*i] != 'c' && format[*i] != 's' && format[*i] != 'p'
			&& format[*i] != 'd' && format[*i] != 'i' && format[*i] != 'o'
			&& format[*i] != 'u' && format[*i] != 'x' && format[*i] != 'X'
			&& format[*i] != 'f' && format[*i] != '%' && format[*i] != '\0')
		(*i) = *i + 1;
}

void		increment_error(const char *f, int *i, int *b)
{
	int			t;
	int			j;
	t_flag		flag;

	starter(&t, &j, i);
	capture_the_flag(f, t, &flag);
	while (f[j] != '\0' && f[j] != '%')
	{
		if (f[j] < 58 || f[j] > 126)
		{
			if ((f[j] >= '0' && f[j] <= '9')
					|| f[j] == '.' || f[j] == '+' || f[j] == '#')
				(*i)++;
			else if (f[j] == '-')
			{
				give_b_the_value(f, t, b);
				(*i)++;
			}
			else if (f[j] == ' ')
				(*i)++;
		}
		if (increment_error1(f, i, j) == -1)
			return ;
		j++;
	}
}
