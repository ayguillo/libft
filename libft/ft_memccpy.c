/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:40:12 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 13:24:21 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*str;
	size_t				i;

	i = 0;
	ptr = dst;
	str = src;
	while (i < n)
	{
		ptr[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (&ptr[i + 1]);
		i++;
	}
	return (NULL);
}
