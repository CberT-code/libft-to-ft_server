/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:40:39 by cbertola          #+#    #+#             */
/*   Updated: 2019/12/13 02:23:40 by cbertola         ###   ########.fr       */
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

	printf("lol\n");
		rslt = ft_printf("466 %d\t%%*.*d\t\t: |%*.*d|\n", i, 2, -1, 0);
		rslt2 = printf("466 %d\t%%*.*d\t\t: |%*.*d|\n", i, 2, -1, 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("i%%--12.7dt%%04i %04.2%% et %%c titi\n", 125, 124, 256);
		rslt = ft_printf("%--12.7dt%04i %04.2% et %c titi\n", 125, 124, 44);
		rslt2 = printf("%--12.7dt%04i %04.2% et %c titi\n", 125, 124, 44);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("u%%4.2ss %%-1.s %%---5.3s i\n", "coco", NULL, "yooo");
		rslt = ft_printf("|%-1.s|\n", NULL, "yooo");
		rslt2 = printf("|%-1.s|\n", NULL, "yooo");
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%d , 0\n");
		rslt = ft_printf("|%d|\n", 0);
		rslt2 = printf("|%d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%.d , 0\n");
		rslt = ft_printf("|%.d|\n", 0);
		rslt2 = printf("|%.d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%04.d , 0\n");
		rslt = ft_printf("|%04.d|\n", 0);
		rslt2 = printf("|%04.d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%0.4d , 0\n");
		rslt = ft_printf("|%0.4d|\n", 0);
		rslt2 = printf("|%0.4d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%4.0d , 0\n");
		rslt = ft_printf("|%4.0d|\n", 0);
		rslt2 = printf("|%4.0d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%4.5d , 0\n");
		rslt = ft_printf("|%4.5d|\n", 0);
		rslt2 = printf("|%4.5d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%6.4d , 0\n");
		rslt = ft_printf("|%6.4d|\n", 0);
		rslt2 = printf("|%6.4d|\n", 0);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 

	printf(" ------------------------\n\t 42 \n------------------------\n");
	printf("%%.d , 42\n");
		rslt = ft_printf("|%.d|\n", 42);
		rslt2 = printf("|%.d|\n", 42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%04.d , 42\n");
		rslt = ft_printf("|%04.d|\n", 42);
		rslt2 = printf("|%04.d|\n", 42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%0.4d , 42\n");
		rslt = ft_printf("|%0.4d|\n", 42);
		rslt2 = printf("|%0.4d|\n", 42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%4.0d , 42\n");
		rslt = ft_printf("|%4.0d|\n", 42);
		rslt2 = printf("|%4.0d|\n", 42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%4.5d , 42\n");
		rslt = ft_printf("|%4.5d|\n", 42);
		rslt2 = printf("|%4.5d|\n", 42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%6.4d , 42\n");
		rslt = ft_printf("|%6.4d|\n", 42);
		rslt2 = printf("|%6.4d|\n", 42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 

	printf(" ------------------------\n\t -42 \n------------------------\n");
	printf("%%.d , -42\n");
		rslt = ft_printf("|%.d|\n", -42);
		rslt2 = printf("|%.d|\n", -42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%04.d , -42\n");
		rslt = ft_printf("|%04.d|\n", -42);
		rslt2 = printf("|%04.d|\n", -42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%0.4d , -42\n");
		rslt = ft_printf("|%0.4d|\n", -42);
		rslt2 = printf("|%0.4d|\n", -42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%4.0d , -42\n");
		rslt = ft_printf("|%4.0d|\n", -42);
		rslt2 = printf("|%4.0d|\n", -42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%4.5d , -42\n");
		rslt = ft_printf("|%4.5d|\n", -42);
		rslt2 = printf("|%4.5d|\n", -42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
	printf("%%6.4d , -42\n");
		rslt = ft_printf("|%6.4d|\n", -42);
		rslt2 = printf("|%6.4d|\n", -42);
		printf("ft_printf = %d, printf = %d\n", rslt, rslt2); 
    return 0; 
} 
