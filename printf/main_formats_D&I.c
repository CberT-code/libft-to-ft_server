#include "ft_printf.h"
#include <stdio.h>

int main()
{
/*    char *str = "hello !";
    char *vide = "";
    char *ptr_nul = NULL;
    char c = 'c';
    char char_nul = 0;
    char char_sp = ' '; */
    int my_ret;

 printf("\n***************\nFORMAT D\n***************\n\n");
    printf(">> Precision = 0______________________________________________________________________________________________\n");
	ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.0d|\t|%12.0d|\t|%12.0d|\t|%12.0d|\t|%12.0d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.0d|\t|%12.0d|\t|%12.0d|\t|%12.0d|\t|%12.0d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.0d|\t|%-12.0d|\t|%-12.0d|\t|%-12.0d|\t|%-12.0d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.0d|\t|%-12.0d|\t|%-12.0d|\t|%-12.0d|\t|%-12.0d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> Precision = 1______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.1d|\t|%12.1d|\t|%12.1d|\t|%12.1d|\t|%12.1d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.1d|\t|%12.1d|\t|%12.1d|\t|%12.1d|\t|%12.1d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.1d|\t|%-12.1d|\t|%-12.1d|\t|%-12.1d|\t|%-12.1d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.1d|\t|%-12.1d|\t|%-12.1d|\t|%-12.1d|\t|%-12.1d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> Precision = 6______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.6d|\t|%12.6d|\t|%12.6d|\t|%12.6d|\t|%12.6d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.6d|\t|%12.6d|\t|%12.6d|\t|%12.6d|\t|%12.6d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.6d|\t|%-12.6d|\t|%-12.6d|\t|%-12.6d|\t|%-12.6d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.6d|\t|%-12.6d|\t|%-12.6d|\t|%-12.6d|\t|%-12.6d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> Precision = 12______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.12d|\t|%12.12d|\t|%12.12d|\t|%12.12d|\t|%12.12d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.12d|\t|%12.12d|\t|%12.12d|\t|%12.12d|\t|%12.12d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.12d|\t|%-12.12d|\t|%-12.12d|\t|%-12.12d|\t|%-12.12d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.12d|\t|%-12.12d|\t|%-12.12d|\t|%-12.12d|\t|%-12.12d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width && Precision = 0____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.0d|\t|%012.0d|\t|%012.0d|\t|%012.0d|\t|%012.0d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.0d|\t|%012.0d|\t|%012.0d|\t|%012.0d|\t|%012.0d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width && Precision = 1____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.1d|\t|%012.1d|\t|%012.1d|\t|%012.1d|\t|%012.1d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.1d|\t|%012.1d|\t|%012.1d|\t|%012.1d|\t|%012.1d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width && Precision = 6____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.6d|\t|%012.6d|\t|%012.6d|\t|%012.6d|\t|%012.6d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.6d|\t|%012.6d|\t|%012.6d|\t|%012.6d|\t|%012.6d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width &&  Precision = 12___________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.12d|\t|%012.12d|\t|%012.12d|\t|%012.12d|\t|%012.12d|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.12d|\t|%012.12d|\t|%012.12d|\t|%012.12d|\t|%012.12d|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    
    printf("\n/!\\ UNDEFINED BEHAVIOR = flag - && 0width\n");
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.0d|\t|%-012.0d|\t|%-012.0d|\t|%-012.0d|\t|%-012.0d|\n", pos, neg, z, max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.1d|\t|%-012.1d|\t|%-012.1d|\t|%-012.1d|\t|%-012.1d|\n", pos, neg, z, max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.6d|\t|%-012.6d|\t|%-012.6d|\t|%-012.6d|\t|%-012.6d|\n", pos, neg, z, max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.12d|\t|%-012.12d|\t|%-012.12d|\t|%-012.12d|\t|%-012.12d|\n", pos, neg, z, max, min);

    printf("\n***************\nFORMAT I\n***************\n\n");

    printf(">> Precision = 0______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.0i|\t|%12.0i|\t|%12.0i|\t|%12.0i|\t|%12.0i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.0i|\t|%12.0i|\t|%12.0i|\t|%12.0i|\t|%12.0i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.0i|\t|%-12.0i|\t|%-12.0i|\t|%-12.0i|\t|%-12.0i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.0i|\t|%-12.0i|\t|%-12.0i|\t|%-12.0i|\t|%-12.0i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> Precision = 1______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.1i|\t|%12.1i|\t|%12.1i|\t|%12.1i|\t|%12.1i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.1i|\t|%12.1i|\t|%12.1i|\t|%12.1i|\t|%12.1i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.1i|\t|%-12.1i|\t|%-12.1i|\t|%-12.1i|\t|%-12.1i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.1i|\t|%-12.1i|\t|%-12.1i|\t|%-12.1i|\t|%-12.1i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> Precision = 6______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.6i|\t|%12.6i|\t|%12.6i|\t|%12.6i|\t|%12.6i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.6i|\t|%12.6i|\t|%12.6i|\t|%12.6i|\t|%12.6i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.6i|\t|%-12.6i|\t|%-12.6i|\t|%-12.6i|\t|%-12.6i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.6i|\t|%-12.6i|\t|%-12.6i|\t|%-12.6i|\t|%-12.6i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> Precision = 12______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.12i|\t|%12.12i|\t|%12.12i|\t|%12.12i|\t|%12.12i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.12i|\t|%12.12i|\t|%12.12i|\t|%12.12i|\t|%12.12i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.12i|\t|%-12.12i|\t|%-12.12i|\t|%-12.12i|\t|%-12.12i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.12i|\t|%-12.12i|\t|%-12.12i|\t|%-12.12i|\t|%-12.12i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width && Precision = 0____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.0i|\t|%012.0i|\t|%012.0i|\t|%012.0i|\t|%012.0i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.0i|\t|%012.0i|\t|%012.0i|\t|%012.0i|\t|%012.0i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width && Precision = 1____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.1i|\t|%012.1i|\t|%012.1i|\t|%012.1i|\t|%012.1i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.1i|\t|%012.1i|\t|%012.1i|\t|%012.1i|\t|%012.1i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width && Precision = 6____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.6i|\t|%012.6i|\t|%012.6i|\t|%012.6i|\t|%012.6i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.6i|\t|%012.6i|\t|%012.6i|\t|%012.6i|\t|%012.6i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf(">> 0width &&  Precision = 12___________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.12i|\t|%012.12i|\t|%012.12i|\t|%012.12i|\t|%012.12i|\n", pos, neg, z, max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.12i|\t|%012.12i|\t|%012.12i|\t|%012.12i|\t|%012.12i|\n", pos, neg, z, max, min);
    printf("\t\tRET = %d\tret2 = %d\n", ret, ret2);

    printf("\n/!\\ UNDEFINED BEHAVIOR = flag - && 0width\n");
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.0i|\t|%-012.0i|\t|%-012.0i|\t|%-012.0i|\t|%-012.0i|\n", pos, neg, z, max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.1i|\t|%-012.1i|\t|%-012.1i|\t|%-012.1i|\t|%-012.1i|\n", pos, neg, z, max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.6i|\t|%-012.6i|\t|%-012.6i|\t|%-012.6i|\t|%-012.6i|\n", pos, neg, z, max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.12i|\t|%-012.12i|\t|%-012.12i|\t|%-012.12i|\t|%-012.12i|\n", pos, neg, z, max, min);

}
