/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstriter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:25:44 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/09 10:28:04 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bstriter(t_bst **tree, void (*func)(t_bst *))
{
	if (!tree || !*tree || !func)
		return ;
	ft_bstiter(&(*tree)->right, func);
	(*func)(*tree);
	ft_bstiter(&(*tree)->left, func);
	return ;
}
