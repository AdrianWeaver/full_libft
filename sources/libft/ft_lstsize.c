/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:24:20 by aweaver           #+#    #+#             */
/*   Updated: 2024/05/31 08:58:51 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	size_t	i;
	t_list	*start;

	i = 0;
	start = list;
	while (list)
	{
		i++;
		if (list->next != start)
			list = list->next;
		else
			return (i);
	}
	return (i);
}
