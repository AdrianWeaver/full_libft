/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:22:42 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/09 11:55:39 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstclear(t_bst **head, void (*del)(void *))
{
	ft_bstiterdepthfirst(head, del);
	if (!head)
		return;
	*head = NULL;
}
