/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstriter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:25:44 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 15:13:55 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bst.h"

void	ft_bstriter(t_bst **tree, void (*func)(void *))
{
	if (!tree || !*tree || !func)
		return ;
	ft_bstriter(&(*tree)->right, func);
	(*func)((*tree)->content);
	ft_bstriter(&(*tree)->left, func);
	return ;
}
