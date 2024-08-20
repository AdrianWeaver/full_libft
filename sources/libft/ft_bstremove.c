/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:41 by aweaver           #+#    #+#             */
/*   Updated: 2024/08/20 09:37:05 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*static t_bst *find_lowest_east_node(t_bst *subtree)
{
	t_bst	*node;


	node = subtree;
	if (!subtree)
		return ;
	while (node->left)
		node = node->left;
	if (node = subtree

}
*/

static t_bst	*ft_remove_fertile_node(t_bst **head, t_bst *parent,
	t_bst *node, void (*del)(void *))
{
	(void)del;
	(void)head;
	(void)parent;
	return (node);
}

void	ft_remove_node(t_bst **head, t_bst *parent, t_bst *node,
	void (*del)(void *))
{
	t_bst	*child_to_keep;

	if (!head)
		return ;
	if (node->left)
		child_to_keep = node->left;
	else
		child_to_keep = node->right;
	if (parent == NULL)
	{
		*head = child_to_keep;
		return ;
	}
	if (parent->right == node)
		parent->right = child_to_keep;
	else
		parent->left = child_to_keep;
	del(node);
	node = NULL;
}

void	ft_bstremove(t_bst **head, void *data_ref, int (*cmp)(),
	void (*del)(void *))
{
	t_bst	*node;
	t_bst	*parent;

	if (!head || !data_ref || !cmp || !del)
		return ;
	parent = NULL;
	node = *head;
	while (node && (*cmp)(data_ref, node->content))
	{
		parent = node;
		if ((*cmp)(data_ref, node->content) < 0)
			node = node->right;
		else if ((*cmp)(data_ref, node->content) > 0)
			node = node->left;
	}
	if (node)
	{
		if (!(node->right) || !(node->left))
			ft_remove_node(head, parent, node, del);
		else if (node->left && node->right)
			ft_remove_fertile_node(head, parent, node, del);
	}
	return ;
}
