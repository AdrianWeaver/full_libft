/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:40:47 by aweaver           #+#    #+#             */
/*   Updated: 2022/01/16 12:19:21 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int n, int base_len, char *base_format)
{
	long int	nbr;
	int			digits;
	char		*ret;

	nbr = (long)n;
	digits = ft_count_digits(n);
	ret = malloc(sizeof(*ret) * (digits + 1));
	if (!ret)
		return (0);
	ret[digits] = 0;
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr = -nbr;
	}
	printf("digits: %i\n", digits);
	while (nbr > 0)
	{
		ret[digits - 1] = base_format[(nbr % base_len)];
		digits--;
		nbr /= base_len;
	}
	if (n == 0)
		ret[0] = '0';
	return (ret);
}

int	main(void)
{
	printf("itoa : %s\n", ft_itoa_base(10, 16, "0123465789abcdef"));
}