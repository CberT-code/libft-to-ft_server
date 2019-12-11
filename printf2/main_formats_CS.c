#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *str = "hello !";
    char *vide = "";
    char *ptr_nul = NULL;
    char c = 'c';
    char char_nul = 0;
    char char_sp = ' ';
    int max = 2147483647;
    int min = -2147483648;
    int pos = 42;
    int neg = -209;
    int z = 0;
    unsigned int u_max = 4294967295;
    unsigned int u_min = 0;
	int ret = 0;
	int ret2 = 0;

    printf("***************\nFORMAT C\n***************\n-> ignorer +, precision, 0width\n\n");
    printf("COMPORTEMENTS DEFINIS\n");
    ret2 = ft_printf("MY_PRINTF\t['c']\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", c, c, c, c, c);
	ret = printf("VR_PRINTF\t['c']\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", c, c, c, c, c);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
	ret2 = ft_printf("MY_PRINTF\t[null]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
	ret = printf("VR_PRINTF\t[null]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
	ret2 = ft_printf("MY_PRINTF\t[space]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
	ret = printf("VR_PRINTF\t[space]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
	printf("\n/!\\ UNDEFINED BEHAVIOR\n");
    ret2 = ft_printf("MY_PRINTF\t['c']\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", c, c, c, c, c);
    ret = printf("VR_PRINTF\t['c']\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", c, c, c, c, c);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
	ret2 = ft_printf("MY_PRINTF\t[null]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
	ret = printf("VR_PRINTF\t[null]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
	ret2 = ft_printf("MY_PRINTF\t[space]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
	ret = printf("VR_PRINTF\t[space]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
   
    printf("\n***************\nFORMAT S\n***************\n-> ignorer +, 0width\n\n");
    ret2 = ft_printf("MY_PRINTF\t[chaine]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", str, str, str, str, str, str, str, str, str, str);
    ret = printf("VR_PRINTF\t[chaine]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", str, str, str, str, str, str, str, str, str, str);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[chaine -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", str, str, str, str, str, str, str, str, str, str);
    ret = printf("VR_PRINTF\t[chaine -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", str, str, str, str, str, str, str, str, str, str);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
    
    ret2 = ft_printf("MY_PRINTF\t[vide   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
    ret = printf("VR_PRINTF\t[vide   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[vide -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
    ret = printf("VR_PRINTF\t[vide -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[null   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul); 
    ret = printf("VR_PRINTF\t[null   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[null -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    ret = printf("VR_PRINTF\t[null -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
	printf("RET PRINTF = %d,\t RET FT_PRINTF = %d\n",ret, ret2);
}
