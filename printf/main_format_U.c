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

    printf("\n***************\nFORMAT U\n***************\n\n");

    printf(">> Precision = 0______________________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%12.0u|\t|%12.0u|\t|%12.0u|\t|%12.0u|\t|%12.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%12.0u|\t|%12.0u|\t|%12.0u|\t|%12.0u|\t|%12.0u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-12.0u|\t|%-12.0u|\t|%-12.0u|\t|%-12.0u|\t|%-12.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-12.0u|\t|%-12.0u|\t|%-12.0u|\t|%-12.0u|\t|%-12.0u|\n", pos, neg, z, u_max, u_min);

    printf(">> Precision = 1______________________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%12.1u|\t|%12.1u|\t|%12.1u|\t|%12.1u|\t|%12.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%12.1u|\t|%12.1u|\t|%12.1u|\t|%12.1u|\t|%12.1u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-12.1u|\t|%-12.1u|\t|%-12.1u|\t|%-12.1u|\t|%-12.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-12.1u|\t|%-12.1u|\t|%-12.1u|\t|%-12.1u|\t|%-12.1u|\n", pos, neg, z, u_max, u_min);

    printf(">> Precision = 6______________________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%12.6u|\t|%12.6u|\t|%12.6u|\t|%12.6u|\t|%12.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%12.6u|\t|%12.6u|\t|%12.6u|\t|%12.6u|\t|%12.6u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-12.6u|\t|%-12.6u|\t|%-12.6u|\t|%-12.6u|\t|%-12.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-12.6u|\t|%-12.6u|\t|%-12.6u|\t|%-12.6u|\t|%-12.6u|\n", pos, neg, z, u_max, u_min);

    printf(">> Precision = 12______________________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%12.12u|\t|%12.12u|\t|%12.12u|\t|%12.12u|\t|%12.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%12.12u|\t|%12.12u|\t|%12.12u|\t|%12.12u|\t|%12.12u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-12.12u|\t|%-12.12u|\t|%-12.12u|\t|%-12.12u|\t|%-12.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-12.12u|\t|%-12.12u|\t|%-12.12u|\t|%-12.12u|\t|%-12.12u|\n", pos, neg, z, u_max, u_min);

    printf(">> 0width && Precision = 0____________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%012.0u|\t|%012.0u|\t|%012.0u|\t|%012.0u|\t|%012.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%012.0u|\t|%012.0u|\t|%012.0u|\t|%012.0u|\t|%012.0u|\n", pos, neg, z, u_max, u_min);

    printf(">> 0width && Precision = 1____________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%012.1u|\t|%012.1u|\t|%012.1u|\t|%012.1u|\t|%012.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%012.1u|\t|%012.1u|\t|%012.1u|\t|%012.1u|\t|%012.1u|\n", pos, neg, z, u_max, u_min);

    printf(">> 0width && Precision = 6____________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%012.6u|\t|%012.6u|\t|%012.6u|\t|%012.6u|\t|%012.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%012.6u|\t|%012.6u|\t|%012.6u|\t|%012.6u|\t|%012.6u|\n", pos, neg, z, u_max, u_min);

    printf(">> 0width &&  Precision = 12___________________________________________________________________________________\n");
    ft_printf("MY_PRINTF\t[no flag]\t|%012.12u|\t|%012.12u|\t|%012.12u|\t|%012.12u|\t|%012.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[no flag]\t|%012.12u|\t|%012.12u|\t|%012.12u|\t|%012.12u|\t|%012.12u|\n", pos, neg, z, u_max, u_min);

/*    printf("\n/!\\ UNDEFINED BEHAVIOR = flag +\n");
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.0u|\t|%+-12.0u|\t|%-+12.0u|\t|%+-12.0u|\t|%+-12.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-12.0u|\t|%+-12.0u|\t|%-+12.0u|\t|%-+12.0u|\t|%+-12.0u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+12.0u|\t|%+12.0u|\t|%+12.0u|\t|%+12.0u|\t|%+12.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+12.0u|\t|%+12.0u|\t|%+12.0u|\t|%+12.0u|\t|%+12.0u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.1u|\t|%+-012.1u|\t|%-+012.1u|\t|%+-012.1u|\t|%+-012.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-012.1u|\t|%+-012.1u|\t|%-+012.1u|\t|%-+012.1u|\t|%+-012.1u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.6u|\t|%+-12.6u|\t|%-+12.6u|\t|%+-12.6u|\t|%+-12.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-12.6u|\t|%+-12.6u|\t|%-+12.6u|\t|%-+12.6u|\t|%+-12.6u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+12.6u|\t|%+12.6u|\t|%+12.6u|\t|%+12.6u|\t|%+12.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+12.6u|\t|%+12.6u|\t|%+12.6u|\t|%+12.6u|\t|%+12.6u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.12u|\t|%+-12.12u|\t|%-+12.12u|\t|%+-12.12u|\t|%+-12.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-12.12u|\t|%+-12.12u|\t|%-+12.12u|\t|%-+12.12u|\t|%+-12.12u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+12.12u|\t|%+12.12u|\t|%+12.12u|\t|%+12.12u|\t|%+12.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+12.12u|\t|%+12.12u|\t|%+12.12u|\t|%+12.12u|\t|%+12.12u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.0u|\t|%+-012.0u|\t|%-+012.0u|\t|%+-012.0u|\t|%+-012.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-012.0u|\t|%+-012.0u|\t|%-+012.0u|\t|%-+012.0u|\t|%+-012.0u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+012.0u|\t|%+012.0u|\t|%+012.0u|\t|%+012.0u|\t|%+012.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+012.0u|\t|%+012.0u|\t|%+012.0u|\t|%+012.0u|\t|%+012.0u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.1u|\t|%+-012.1u|\t|%-+012.1u|\t|%+-012.1u|\t|%+-012.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-012.1u|\t|%+-012.1u|\t|%-+012.1u|\t|%-+012.1u|\t|%+-012.1u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\t|%+012.1u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.6u|\t|%+-012.6u|\t|%-+012.6u|\t|%+-012.6u|\t|%+-012.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-012.6u|\t|%+-012.6u|\t|%-+012.6u|\t|%-+012.6u|\t|%+-012.6u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+012.6u|\t|%+012.6u|\t|%+012.6u|\t|%+012.6u|\t|%+012.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+012.6u|\t|%+012.6u|\t|%+012.6u|\t|%+012.6u|\t|%+012.6u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.12u|\t|%+-012.12u|\t|%-+012.12u|\t|%+-012.12u|\t|%+-012.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +-]\t|%+-012.12u|\t|%+-012.12u|\t|%-+012.12u|\t|%-+012.12u|\t|%+-012.12u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag +]\t|%+012.12u|\t|%+012.12u|\t|%+012.12u|\t|%+012.12u|\t|%+012.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag +]\t|%+012.12u|\t|%+012.12u|\t|%+012.12u|\t|%+012.12u|\t|%+012.12u|\n", pos, neg, z, u_max, u_min);
*/
    printf("\n/!\\ UNDEFINED BEHAVIOR = flag - && 0width\n");
    ft_printf("MY_PRINTF\t[flag -]\t|%-012.0u|\t|%-012.0u|\t|%-012.0u|\t|%-012.0u|\t|%-012.0u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-012.0u|\t|%-012.0u|\t|%-012.0u|\t|%-012.0u|\t|%-012.0u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-012.1u|\t|%-012.1u|\t|%-012.1u|\t|%-012.1u|\t|%-012.1u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-012.1u|\t|%-012.1u|\t|%-012.1u|\t|%-012.1u|\t|%-012.1u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-012.6u|\t|%-012.6u|\t|%-012.6u|\t|%-012.6u|\t|%-012.6u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-012.6u|\t|%-012.6u|\t|%-012.6u|\t|%-012.6u|\t|%-012.6u|\n", pos, neg, z, u_max, u_min);
    ft_printf("MY_PRINTF\t[flag -]\t|%-012.12u|\t|%-012.12u|\t|%-012.12u|\t|%-012.12u|\t|%-012.12u|\n", pos, neg, z, u_max, u_min);
    printf("VRAI_PRINTF\t[flag -]\t|%-012.12u|\t|%-012.12u|\t|%-012.12u|\t|%-012.12u|\t|%-012.12u|\n", pos, neg, z, u_max, u_min);

}
