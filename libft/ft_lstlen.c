/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:23:59 by tdelabro          #+#    #+#             */
/*   Updated: 2019/01/21 13:23:27 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstlen(t_list *lst)
{
	int		c;
	t_list	*head;

	c = 0;
	head = lst;
	while (head)
	{
		c++;
		head = head->next;
	}
	return (c);
}
