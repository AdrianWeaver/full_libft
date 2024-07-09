/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:36:23 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/09 10:28:09 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bstiter(t_bst **tree, void (*func)(t_bst *))
{
	if (!tree || !*tree || !func)
		return ;
	ft_bstiter(&(*tree)->left, func);
	(*func)(*tree);
	ft_bstiter(&(*tree)->right, func);
	return ;
}
