/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:23:18 by lalmahth          #+#    #+#             */
/*   Updated: 2024/12/09 17:49:26 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<stdio.h>
# include<unistd.h>
# include<string.h>

int			ft_printf(const char *format, ...);
void		ft_putnbr(int n);
void		ft_putnumu(unsigned int n);
void		ft_hex_to_char(int n, char r);
int			ft_search3(va_list ap, char c, int i);
int			ft_search2(va_list ap, char c, int i);
int			ft_search(va_list ap, char c, int i);
int			ft_putchar(char c);
int			ft_hx16p(unsigned long int num);
int			ft_hx16(unsigned int n, int i);
int			ft_hx16k(unsigned int n, int i);
int			lennum(long n);

#endif
