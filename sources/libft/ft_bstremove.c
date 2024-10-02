/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:41 by aweaver           #+#    #+#             */
/*   Updated: 2024/10/02 10:25:06 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"
#include <stdio.h>
#include <stdlib.h>

static t_bst *find_lowest_east_node(t_bst *node)
{
	t_bst	*heir;
	t_bst	*heir_parent = node;

	if (!node)
		return (NULL);
	heir = node->right;
	if (!heir)
		return (NULL);
	while (heir->left)
	{
		heir_parent = heir;
		heir = heir->left;
	}
	if (heir_parent != node)
	{
		if (heir->right)
		{
			heir_parent->left = heir->right;
			heir->right = NULL;
		}
		heir_parent->left = NULL;
	}
	return (heir);
}

static void	ft_remove_fertile_node(t_bst **head, t_bst *parent, t_bst *node, void (*delcontent)(void *))
{
	t_bst	*heir;

	heir = find_lowest_east_node(node);
	//if node to be deleted is head of tree
	if (!parent)
		*head = heir;
	//reconnecting heir with upper tree.
	else if (parent->right == node)
		parent->right = heir;
	else if (parent->left == node)
		parent->left = heir;
	//reconnecting heir with lower tree
	if (node->right != heir)
		heir->right = node->right;
	heir->left = node->left;
	(*delcontent)(node->content);
	free(node);
}

static void	ft_remove_node(t_bst **head, t_bst *parent, t_bst *node,
	void (*delcontent)(void *))
{
	t_bst	*heir;

	if (node->left)
		heir = node->left;
	else
		heir = node->right;
	//if node to be remove is the head of the tree
	if (parent == NULL)
		*head = heir;
	else if (parent->right == node)
		parent->right = heir;
	else if (parent->left == node)
		parent->left = heir;
	(*delcontent)(node->content);
	free(node);
}

/*
 *	@brief this removes one node in the bst and assures that the bst
 *	is still valid
 *
 *	@param head is the head of the bst
 *	@param data_ref is a content, the node where the content is equal to this
 *	is to be removed
 *	@param cmp is the function used to sort the tree, it has to be the same one
 *	used to insert new params
 *
 *	@delcontent is the function used to remove the CONTENT of the tree.
*/
void	ft_bstremove(t_bst **head, void *data_ref, int (*cmp)(),
	void (*delcontent)(void *))
{
	t_bst	*node;
	t_bst	*parent;
	int		comparison_result;

	if (!head || !data_ref || !cmp || !delcontent)
		return ;
	parent = NULL;
	node = *head;
	if (!node)
		return;
	//searching the node through the tree
	while (node)
	{
		comparison_result = (*cmp)(data_ref, node->content);
		//node found removing it
		if (comparison_result == 0)
		{
			if (!(node->right) || !(node->left))
			{
				ft_remove_node(head, parent, node, delcontent);
			}
			else if (node->left && node->right)
			{
				ft_remove_fertile_node(head, parent, node, delcontent);
				return ;
			}
			return;
		}
		parent = node;
		//node to find might be to the right of the current node
		if (comparison_result > 0)
			node = node->right;
		//node to find might be to the left of the current node
		if (comparison_result < 0)
			node = node->left;
	}
}

/*
 *	@brief this removes one node in the bst and assures that the bst
 *	is still valid
 *
 *	@param head is the head of the bst
 *	@param node_address is the address of the node trying to be removed (see ft_bstsearch)
 *	@param cmp is the function used to sort the tree, it has to be the same one
 *	used to insert new params
 *
 *	@delcontent is the function used to remove the CONTENT of the tree.
*/
void	ft_bstremove_address(t_bst **head, t_bst *node_address, int (*cmp)(),
	void (*delcontent)(void *))
{
	t_bst	*node;
	t_bst	*parent;
	int		comparison_result;

	if (!head || !node_address || !cmp || !delcontent)
		return ;
	parent = NULL;
	node = *head;
	if (!node)
		return;
	//searching the node through the tree
	while (node)
	{
		if (node == node_address)
		comparison_result = (*cmp)(node_address->content, node->content);
		//node found removing it
		if (comparison_result == 0)
		{
			if (!(node->right) || !(node->left))
			{
				ft_remove_node(head, parent, node, delcontent);
				return ;
			}
			else if (node->left && node->right)
			{
				ft_remove_fertile_node(head, parent, node, delcontent);
				return ;
			}
		}
		//node to find might be to the right of the current node
		if (comparison_result > 0)
			node = node->right;
		//node to find might be to the left of the current node
		if (comparison_result < 0)
			node = node->left;
	}
}
