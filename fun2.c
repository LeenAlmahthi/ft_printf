/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:53:42 by lalmahth          #+#    #+#             */
/*   Updated: 2024/12/09 16:54:52 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnumu(unsigned int n)
{
	char	r;

	if (n > 9)
		ft_putnumu(n / 10);
	r = n % 10 + '0';
	write (1, &r, 1);
}

void	ft_hex_to_char(int n, char r)
{
	char	c;

	if (n >= 10 && n <= 15)
	{
		c = 'a' + (n - 10);
		if (r == 'X')
			c -= 32;
		write(1, &c, 1);
	}
}
