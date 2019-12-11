/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:15:51 by cbertola          #+#    #+#             */
/*   Updated: 2019/12/11 18:29:23 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int			ft_count_char_int(long int nb, int base)
{
	int			count;
	long int	i;
	
	if (base == 0)
		return (-1);
	count = 0;
	i = nb;
	if (i <= 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= base;
		count++;
	}
	return (count);
}

void		ft_width(va_list ap, t_flags *flags, char **str, int i)
{
	int nb;

	flags->arg = flags->arg | (1 << i);
	while (*(*str) == '-')
		(*str)++;
	while (*(*str) == '0')
		(*str)++;
	if ((nb = ft_atoi(*str)) > 0)
	{
		flags->width = nb;
		*str = (*str + ft_count_char_int(flags->width, 10));
	}
	else if (*(*str) == '*')
	{
		flags->width = va_arg(ap, int);
		(*str)++;
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->arg = flags->arg | (1 << 1);
		}
	}
	else
		flags->arg = flags->arg & ~ (1 << i);
}

int			ft_precis(va_list ap, t_flags *flags, char **str)
{
	int nb;

	flags->arg = flags->arg | (1 << 3);
	(*str)++;
	while (*(*str) == '0')
		(*str)++;
	//printf("le char avant atoi = %c\n", *(*str));
	if ((nb = ft_atoi(*str)) > 0)
	{
		flags->precis = nb;
		*str = (*str + ft_count_char_int(flags->precis, 10));
	//printf("le char apres atoi est = %c\n", *(*str));
	}
	else if (*(*str) == '*')
	{
		flags->precis = va_arg(ap, int);
		if (flags->precis < 0)
			return (0);
		(*str)++;
	}
	else 
		flags->arg = flags->arg & ~ (1 << 3);
	return (1);
}

void			ft_init_mask(t_flags *flags, long int nb, int base)
{
	int nbc;

	if	((nbc = ft_count_char_int(nb, base)) == -1)
		nbc = nb;
	if (flags->arg & POINT)
	{
		if ((flags->precis -= nbc) < 0)
			flags->precis = 0;
		if ((flags->width -= nbc + flags->precis) < 0)
			flags->width = 0;
	}
	else
	{
		if ((flags->width -= nbc) < 0)
			flags->width = 0;
	}
}

