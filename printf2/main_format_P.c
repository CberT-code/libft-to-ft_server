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

    printf("\n***************\nFORMAT P\n***************\n\n");
    ft_printf("MY_PRINTF\t[chaine]\t|%p|\t|%-p|\t|%12p|\t|%-12p|\t|%3p|\t|%-3p|\n", str, str, str, str, str, str);
    printf("VRAI_PRINTF\t[chaine]\t|%p|\t|%-p|\t|%12p|\t|%-12p|\t|%3p|\t|%-3p|\n", str, str, str, str, str, str);
    ft_printf("MY_PRINTF\t[NULL]\t|%p|\t|%-p|\t|%12p|\t|%-12p|\t|%3p|\t|%-3p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    printf("VRAI_PRINTF\t[NULL]\t|%p|\t|%-p|\t|%12p|\t|%-12p|\t|%3p|\t|%-3p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    printf("\n/!\\ UNDEFINED BEHAVIOR\n");
    ft_printf("|%0p|, |%012p|, |%03p|\n", str, str, str);
    ft_printf("|%.p|, |%.12p|, |%.3p|, |%.0p|\n", str, str, str, str);
    ft_printf("|%-.p|, |%-.12p|, |%-.3p|, |%-.0p|\n", str, str, str, str);
    ft_printf("|%12.p|, |%12.12p|, |%12.3p|, |%12.0p|\n", str, str, str, str);
    ft_printf("|%-12.p|, |%-12.12p|, |%-12.3p|, |%-12.0p|\n", str, str, str, str);
    ft_printf("|%+-p|, |%+12p|, |%+012p|, |%+03p|, |%+0p|, |%+-12p|, |%+.12p|, |%+-.12p|, |%+.0p|, |%+-.0p|, |%+3p|, |%+-3p|, |%+.3p|, |%+-.3p|", str, str, str, str, str, str, str, str, str, str, str, str, str, str);
    ft_printf("|%0p|, |%012p|, |%03p|\n", ptr_nul, ptr_nul, ptr_nul);
    ft_printf("|%.p|, |%.12p|, |%.3p|, |%.0p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    ft_printf("|%-.p|, |%-.12p|, |%-.3p|, |%-.0p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    ft_printf("|%12.p|, |%12.12p|, |%12.3p|, |%12.0p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    ft_printf("|%-12.p|, |%-12.12p|, |%-12.3p|, |%-12.0p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    ft_printf("|%+-p|, |%+12p|, |%+012p|, |%+03p|, |%+0p|, |%+-12p|, |%+.12p|, |%+-.12p|, |%+.0p|, |%+-.0p|, |%+3p|, |%+-3p|, |%+.3p|, |%+-.3p|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
}
