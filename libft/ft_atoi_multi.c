/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:15:05 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/03 17:27:45 by cyrillebe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_atoi_multi(const char *str)
{
	int n;
	int result;
	int temp[100];
	int j;

	n = 1;
	j = 0;
	result = 0;
	while (*str)
	{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			n = -1;
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += (*str - 48);
		str++;
	}
	temp[j++] = n * result;
	if (*str != '\' || *str != ' ' || *str != ',' || *str == '\n')
		return (temp);
	}
}
