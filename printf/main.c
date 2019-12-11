/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:40:39 by cbertola          #+#    #+#             */
/*   Updated: 2019/12/10 20:33:23 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main() 
{ 
    int num = -42; 
    void *ptr;
	int i = 14;
	int rslt = 0;
	int rslt2 = 0;
int		ret;

	ptr = &num;

		rslt = ft_printf("%.d\n", 44);
		rslt2 = printf("%.d\n", 44);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("%.0d\n", 5);
		rslt2 = printf("%.0d\n", 5);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("%0d\n", -579);
		rslt2 = printf("%0d\n", -579);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("%0010.4d\n", 0);
		rslt2 = printf("%0010.4d\n", 0);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("%04d\n", 0);
		rslt2 = printf("%04d\n", 0);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("%----24p et hello %2p %12p\n", &ret, &main, NULL);
		rslt2 = printf("%----24p et hello %2p %12p\n", &ret, &main, NULL);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("%20p\n", ptr);
		rslt2 = printf("%20p\n", ptr);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
		rslt = ft_printf("|%-25p|\n", ptr);
		rslt2 = printf("|%-25p|\n", ptr);
	printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
    return 0; 
} 
