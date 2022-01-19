/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:58:31 by aweaver           #+#    #+#             */
/*   Updated: 2022/01/19 09:59:52 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* the purpose of this function is to count the length of a number
 * then return it */

int	ft_count_digits_base(long int nb, int base_len)
{
	int	digits;

	digits = 1;
	if (base_len == 0)
		return (-1);
	if (nb < 0)
	{
		digits++;
		nb = -nb;
	}
	while (nb / base_len > 0)
	{
		nb = nb / base_len;
		digits++;
	}
	return (digits);
}
