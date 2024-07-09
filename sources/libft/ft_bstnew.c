/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:25:35 by aweaver           #+#    #+#             */
/*   Updated: 2024/07/09 09:01:17 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_bst	*ft_bstnew(void *content)
{
	t_bst	*ret;

	ret = malloc(sizeof(*ret) * 1);
	if (!ret)
		return (0);
	ret->content = content;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
