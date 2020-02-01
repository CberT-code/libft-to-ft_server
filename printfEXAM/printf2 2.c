/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:42:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/14 18:15:21 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;

	i = 0;
	while (*str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
		i = i * 10 + (*str++ - 48);
	return (i);
}

int				ft_putstr_int(va_list ap, t_flags *flags)
{
	char		*c;
	int			nb;

	c = va_arg(ap, char *);
	if (!c)
		c = "(null)";
	nb = ft_strlen(c);
	if (!flags->precis && flags->width > nb)
		while (flags->width-- > nb)
			ft_putchar(' ');

	return (1);
}

static int		ft_putnbr_intb(int nb, t_flags *flags)
{
	int			i;
	int			j;
	int			result[11];
	long int	nbr;

	nbr = nb;
	i = 0;
	j = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0 && (flags->precis != -1 || !(flags->arg & POINT)))
		return (ft_putchar_int('0'));
	while (nbr > 0)
	{
		result[i++] = nbr % 10;
		nbr /= 10;
	}
	j += i;
	while (i >= 1)
		ft_putchar(result[--i] + '0');
	return (j);
}

int				ft_putnbr_int(va_list ap, t_flags *flags)
{
	int		nb;

	nb = va_arg(ap, int);
	ft_init_mask(flags, nb, 10);
	flags->rslt += ft_display_before(flags, nb);
	flags->rslt += ft_putnbr_intb(nb, flags);
	if (flags->arg & MINUS)
		while ((flags->width)-- > 0)
			flags->rslt += ft_putchar_int(' ');
	return (1);
}

static int		ft_puthexa_minb(unsigned int nb, t_flags *flags)
{
	char const		*base;
	int				i;
	int				rtn;
	char			result[9];

	base = "0123456789abcdef";
	i = 0;
	if (nb == 0 && (flags->precis != -1 || !(flags->arg & POINT)))
		return (ft_putchar_int('0'));
	while (nb > 0)
	{
		result[i++] = base[nb % 16];
		nb = nb / 16;
	}
	rtn = i;
	while (i > 0)
		ft_putchar(result[--i]);
	return (rtn);
}

int				ft_puthexa_min(va_list ap, t_flags *flags)
{
	unsigned int		nb;

	nb = va_arg(ap,unsigned int);
	ft_init_mask(flags, nb, 16);
	flags->rslt += ft_display_before(flags, nb);
	flags->rslt += ft_puthexa_minb(nb, flags);
	if (flags->arg & MINUS)
		while ((flags->width)-- > 0)
			flags->rslt += ft_putchar_int(' ');
	return (1);
}

