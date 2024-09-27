/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiterdepthfirst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:38:26 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 12:36:51 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_bstiterdepthfirst(t_bst **head, void (*func)(void *), int delete)
{
	if (!head || !(*head) || !func)
		return ;
	ft_bstiterdepthfirst(&(*head)->left, func, delete);
	ft_bstiterdepthfirst(&(*head)->right, func, delete);
	(*func)((*head)->content);
	if (delete == DELETENODES)
	{
		free(*head);
		*head = NULL;
	}
}
