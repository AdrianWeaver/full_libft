/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:40:47 by aweaver           #+#    #+#             */
/*   Updated: 2022/01/19 15:48:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>


static char	*ft_get_ptr(int digits, size_t base_len, char *base_format)
{
	char	*ret;

	if (ft_is_ubase_ok(base_len, base_format) == 0)
		return (NULL);
	ret = malloc(sizeof(*ret) * (digits + 1));
	if (ret != 0)
		ret[digits] = 0;
	return (ret);
}

char	*ft_uitoa_base(size_t n, size_t base_len, char *base_format)
{
	unsigned long int	nbr;
	int					digits;
	char				*ret;

	nbr = n;
	digits = ft_count_digits_base(n, base_len);
	ret = ft_get_ptr(digits, base_len, base_format);
	if (ret == 0)
		return (0);
	if ((nbr > 9 && nbr <= base_len) || n == 0)
		ret[0] = '0';
	while (nbr > 0)
	{
		ret[digits - 1] = base_format[(nbr % base_len)];
		digits--;
		nbr /= base_len;
	}
	return (ret);
}	
