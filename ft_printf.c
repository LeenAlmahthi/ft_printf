/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:54:28 by lalmahth          #+#    #+#             */
/*   Updated: 2024/12/09 18:15:19 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	ft_putnbr(int n)
{
	char	r;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	r = n % 10 + '0';
	write (1, &r, 1);
}

int	ft_search3(va_list ap, char c, int i)
{
	unsigned long	qq;

	if (c == 'p')
	{
		qq = va_arg(ap, unsigned long);
		if (qq == 0)
		{
			write (1, "(nil)", 5);
			return (5);
		}
		i += write (1, "0x", 2);
		i = ft_hx16p(qq) + i;
	}
	else if (c == 'u')
	{
		qq = va_arg(ap, unsigned int);
		i = lennum(qq);
		ft_putnumu(qq);
	}
	else if (c == 'X')
	{
		qq = va_arg(ap, unsigned int);
		i = ft_hx16k(qq, i);
	}
	return (i);
}

int	ft_search2(va_list ap, char c, int i)
{
	unsigned long	qq;
	int				s;

	if (c == 'd' || c == 'i')
	{
		s = va_arg(ap, int);
		i = lennum(s);
		ft_putnbr(s);
		return (i);
	}
	else if (c == '%')
	{
		write (1, "%%", 1);
		return (1);
	}
	else if (c == 'x')
	{
		qq = va_arg(ap, unsigned int);
		i = ft_hx16(qq, i);
		return (i);
	}
	i = ft_search3 (ap, c, i);
	return (i);
}

int	ft_search(va_list ap, char c, int i)
{
	char	*s;
	char	c2;

	i = 0;
	if (c == 'c')
	{
		c2 = va_arg(ap, int);
		return (write (1, &c2, 1));
	}
	else if (c == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
		{
			write (1, "(null)", 6);
			return (6);
		}
		while (s[i] != '\0')
		{
			write (1, &s[i++], 1);
		}
		return (i);
	}
	i = ft_search2(ap, c, i);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		tem;
	int		f;

	i = 0;
	f = 0;
	tem = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			tem += ft_search(ap, s[i], i);
			f++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	i = i - (f * 2);
	return (i + tem);
}
