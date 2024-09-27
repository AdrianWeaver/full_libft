/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:32:38 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 15:13:13 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"
#include <stdio.h>

/*
 *	@brief insert a new node in a binary search tree without duplicates
 *
 *	@param head a pointer on the head of the tree
 *	@param newnode a pointer on an allocated new node to add (see ft_bstnew)
 *	@param cmp a comparison function
 *		cmp returns >0 if new node should be inserted to the right of the node
 *		cmp returns <0 if value should be inserted to the left of the node
 *		cmp returns 0 if value is already present in the tree
 *	@return the inserted node or null if insertion failed
*/
t_bst	*ft_bstinsert(t_bst	**head, t_bst *newnode,
	int (*cmp)(void *, void *))
{
	t_bst	*node;

	//protection for head** and function pointer
	if (!head || !cmp)
		return (NULL);
	node = *head;
	//if binary tree is empty, insert newnode
	if (!node)
	{
		*head = newnode;
		return (newnode);
	}
	while (1)
	{
		//travel to the right of the tree
		if ((*cmp)(newnode->content, node->content) > 0)
		{
			if (node->right == NULL)
			{
				node->right = newnode;
				return (newnode);
			}
			node = node->right;
		}
		//travel to the left of the tree
		if ((*cmp)(newnode->content, node->content) < 0)
		{
			if (node->left == NULL)
			{
				node->left = newnode;
				return (newnode);
			}
			node = node->left;
		}
		//if the cmp value estimates that this is a duplicate
		if ((*cmp)(newnode->content, node->content) == 0)
			return (NULL);
	}
	//this should never happen
	return (NULL);
}
