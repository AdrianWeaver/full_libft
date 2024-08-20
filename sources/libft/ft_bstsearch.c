/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:35:12 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/10 08:42:47 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
