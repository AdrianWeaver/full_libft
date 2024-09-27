/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:35:12 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 15:14:01 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"

t_bst	*ft_bstsearch(t_bst *tree, void *data, int (*cmp)(void *, void *))
{
	if (!tree || !cmp)
		return (NULL);
	if ((*cmp)(tree->content, data) == 0)
		return (tree);
	if (tree->left)
		return (bstsearch(tree->left, data, cmp));
	if (tree->right)
		return (bstsearch(tree->right, data, cmp));
}
