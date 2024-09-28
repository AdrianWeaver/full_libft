/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:35:12 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/28 16:07:17 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"
#include <stddef.h>

t_bst	*ft_bstsearch(t_bst *tree, void *data, int (*cmp)(void *, void *))
{
	int cmp_result = 0;
	t_bst *found = NULL;
	if (!tree || !cmp)
		return (NULL);
	cmp_result = (*cmp)(tree->content, data);
	if (cmp_result == 0)
		return (tree);
	if (cmp_result < 0)
	{
		found = ft_bstsearch(tree->left, data, cmp);
		if (found)
			return (found);
	}
	found = ft_bstsearch(tree->right, data, cmp);
	return (found);
}
