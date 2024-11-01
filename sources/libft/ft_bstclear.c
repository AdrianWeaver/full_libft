/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:22:42 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 15:14:43 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_bstclear(t_bst **head, void (*del)(void *))
{
	ft_bstiterdepthfirst(head, del, DELETENODES);
	if (!head)
		return ;
	free(*head);
	*head = NULL;
}
