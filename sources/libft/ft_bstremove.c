/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:41 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 15:14:22 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"
#include <stdio.h>
#include <stdlib.h>

//TODO: This is still in a development state
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

static void	ft_remove_fertile_node(t_bst *node, void (*delcontent)(void *))
{
	t_bst	*heir_parent;
	t_bst	*heir;

	heir = node->right;
	heir_parent = node;
	while (heir && heir->left)
	{
		heir_parent = heir;
		heir = heir->left;
	}
	(*delcontent)(node);
	node->content = heir->content;
	if (heir_parent == node)
		heir_parent->right = heir->right;
	else
		heir_parent->left = heir->right;
	free(heir);
}

void	ft_remove_node(t_bst **head, t_bst *parent, t_bst *node,
	void (*delcontent)(void *))
{
	t_bst	*child_to_keep;

	if (!head)
		return ;
	if (node->left)
		child_to_keep = node->left;
	else
		child_to_keep = node->right;
	if (node == *head)
		*head = child_to_keep;
	else if (parent->right == node)
		parent->right = child_to_keep;
	else
		parent->left = child_to_keep;
	(*delcontent)(node);
	free(node);
	node = NULL;
}

void	ft_bstremove(t_bst **head, void *data_ref, int (*cmp)(),
	void (*delcontent)(void *))
{
	t_bst	*node;
	t_bst	*parent;

	if (!head || !data_ref || !cmp || !delcontent)
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
			ft_remove_node(head, parent, node, delcontent);
		else if (node->left && node->right)
			ft_remove_fertile_node(node, delcontent);
	}
	return ;
}
