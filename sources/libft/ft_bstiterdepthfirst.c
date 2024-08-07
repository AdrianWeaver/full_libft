/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiterdepthfirst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:38:26 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/09 10:42:46 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstiterdepthfirst(t_bst **head, void (*func)(t_bst *))
{
	if (!head || !(*head) || !func)
		return ;
	ft_bstiterdepthfirst(&(*head)->left, func);
	ft_bstiterdepthfirst(&(*head)->right, func);
	(*func)(*head);
}
