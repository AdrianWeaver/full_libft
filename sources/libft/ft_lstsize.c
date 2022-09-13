/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:24:20 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/02 08:40:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	size_t	i;
	t_list	*start;

	i = 0;
	start = list;
	while (lst)
	{
		i++;
		if (lst->next != start)
			list = list->next;
		else
			return (i);
	}
	return (i);
}
