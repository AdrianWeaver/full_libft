/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:36:23 by aweaver           #+#    #+#             */
/*   Updated: 2024/08/20 14:11:38 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bstiter(t_bst **tree, void (*func)(void *))
{
	if (!tree || !*tree || !func)
		return ;
	ft_bstiter(&(*tree)->left, func);
	(*func)((*tree)->content);
	ft_bstiter(&(*tree)->right, func);
	return ;
}
