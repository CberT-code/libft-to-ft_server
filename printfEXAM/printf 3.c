/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:15:37 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/14 17:43:36 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libc.h>
#include <stdarg.h>

typedef struct	s_flags
{
	int		precis;
	int		width;
	char	arg;
	int		rslt;
}				t_flags;

void		ft_putchar(char c)
{
	write(1,&c,1);
}
int			ft_isfind(char *tab, char c)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_get_flags(char **str, t_flags *flags)
{
	//flags->width = ft_atoi(str);
	if (*(*str) == '.')
	{
		str++;
	//	flags->precis = ft_atoi(str);
	}
}

int		ft_printstr(char **str)
{
	int i;
	
	i = 0;
	while (*(*str) != '%' && *(*str) != '\0')
	{
		ft_putchar(*(*str)++);
		i++;
	}
	return (i);
}
int		ft_get_fct(char **str, va_list ap, t_flags *flags)
{
	int			j;
	int			(*tab[3])(va_list, t_flags *);
	char		*tab_sign;

	tab[0] = &ft_putstr_int;
	tab[1] = &ft_putnbr_int;
	tab[2] = &ft_puthexa_min;
	tab_sign = "sdx";
	j = (ft_isfind(tab_sign, *(*str)));
	(*str)++;
	if (j == -1)
		return (1);
	return ((tab[j])(ap, flags));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	t_flags			flags;

	va_start(ap, format);
	str = (char *)format;
	flags.rslt = 0;
	while (*str)
	{
		flags.rslt += ft_printstr(&str);
		if (*str == '%')
		{
			str++;
			ft_get_flags(&str, &flags);
			ft_get_fct(&str, ap, &flags);
		}
	}
	va_end(ap);
	return (flags.rslt);
}

int		main()
{
	char *test = "coucou je m'appel autrui";

	printf("str %10s", test);
	printf("str %0s", test);
	printf("str %10.5s", test);
	printf("str %5.10s", test);
	printf("str %.10s", test);
}
