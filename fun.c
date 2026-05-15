/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:09:24 by lalmahth          #+#    #+#             */
/*   Updated: 2024/12/09 18:14:17 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_hx16p(unsigned long int num)
{
	char	*arr;
	int		len;
	char	r;

	r = 'p';
	arr = "0123456789abcdef";
	len = 0;
	if (num >= 16)
	{
		len += ft_hx16p(num / 16);
		len += ft_hx16p(num % 16);
	}
	else
	{
		if (num <= 9)
			len += ft_putchar(arr[num]);
		else
		{
			ft_hex_to_char(num, r);
			len++;
		}
	}
	return (len);
}

int	ft_hx16(unsigned int n, int i)
{
	int		re;
	int		s[32];
	int		length;
	char	r;

	i = 0;
	r = 'x';
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		re = n / 16;
		s [i++] = n % 16;
		n = re;
	}
	length = i--;
	while (i >= 0)
	{
		if (s[i] > 9 && s[i] <= 15)
			ft_hex_to_char(s[i], r);
		else
			ft_putnumu(s[i]);
		i--;
	}
	return (length);
}

int	ft_hx16k(unsigned int n, int i)
{
	int		re;
	int		s[32];
	int		length;
	char	r;

	i = 0;
	r = 'X';
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		re = n / 16;
		s [i++] = n % 16;
		n = re;
	}
	length = i--;
	while (i >= 0)
	{
		if (s[i] > 9 && s[i] <= 15)
			ft_hex_to_char(s[i], r);
		else
			ft_putnumu(s[i]);
		i--;
	}
	return (length);
}

int	lennum(long n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (++i);
}
