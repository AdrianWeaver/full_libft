/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:58:48 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/02 09:03:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void*))
{
	t_list	*start;

	if (f == NULL)
		return ;
	start = list;
	while (list)
	{
		f(list->content);
		if (list->next == start)
			return ;
		list = list->next;
	}
}
