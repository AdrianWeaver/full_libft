/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:32:38 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/09 10:27:50 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_bst	*ft_bstinsert(t_bst	**head, t_bst *newnode,
	int (*cmp)(t_bst *, t_bst *))
{
	t_bst	*node;

	if (!head || !cmp)
		return (NULL);
	node = *head;
	if (!node)
		return ((*head = newnode), newnode);
	while (1)
	{
		if ((*cmp)(node, newnode) > 0)
		{
			if (node->right == NULL)
				return (node->right = newnode, newnode);
			node = node->right;
		}
		if ((*cmp)(node, newnode) < 0)
		{
			if (node->left == NULL)
				return (node->left = newnode, newnode);
			node = node->left;
		}
		if ((*cmp)(node, newnode) == 0)
			return (NULL);
	}
	return (NULL);
}
