/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:35:12 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/28 13:25:03 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"
#include <stddef.h>

t_bst	*ft_bstsearch(t_bst *tree, void *data, int (*cmp)(void *, void *))
{
	if (!tree || !cmp)
		return (NULL);
	if ((*cmp)(tree->content, data) == 0)
		return (tree);
	if (tree->left)
		return (ft_bstsearch(tree->left, data, cmp));
	if (tree->right)
		return (ft_bstsearch(tree->right, data, cmp));
	return (NULL);
}
