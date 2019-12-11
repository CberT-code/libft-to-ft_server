#include "ft_printf.h"
#include <stdio.h>

void red()
{
  printf("\033[1;31m");
}

void green()
{
  printf("\033[0;32m");
}

void reset()
{
  printf("\033[0m\n");
}

void color(int ret, int ret2)
{
	if (ret == ret2)
		green();
	else
		red();
}

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

    printf("\n***************\nFORMAT X-MIN\n***************\n\n");

    printf(">> Precision = 0______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.0x|\t|%12.0x|\t|%12.0x|\t|%12.0x|\t|%12.0x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.0x|\t|%12.0x|\t|%12.0x|\t|%12.0x|\t|%12.0x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.0x|\t|%-12.0x|\t|%-12.0x|\t|%-12.0x|\t|%-12.0x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.0x|\t|%-12.0x|\t|%-12.0x|\t|%-12.0x|\t|%-12.0x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> Precision = 1______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.1x|\t|%12.1x|\t|%12.1x|\t|%12.1x|\t|%12.1x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.1x|\t|%12.1x|\t|%12.1x|\t|%12.1x|\t|%12.1x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.1x|\t|%-12.1x|\t|%-12.1x|\t|%-12.1x|\t|%-12.1x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.1x|\t|%-12.1x|\t|%-12.1x|\t|%-12.1x|\t|%-12.1x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> Precision = 6______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.6x|\t|%12.6x|\t|%12.6x|\t|%12.6x|\t|%12.6x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.6x|\t|%12.6x|\t|%12.6x|\t|%12.6x|\t|%12.6x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.6x|\t|%-12.6x|\t|%-12.6x|\t|%-12.6x|\t|%-12.6x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.6x|\t|%-12.6x|\t|%-12.6x|\t|%-12.6x|\t|%-12.6x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> Precision = 12______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.12x|\t|%12.12x|\t|%12.12x|\t|%12.12x|\t|%12.12x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.12x|\t|%12.12x|\t|%12.12x|\t|%12.12x|\t|%12.12x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.12x|\t|%-12.12x|\t|%-12.12x|\t|%-12.12x|\t|%-12.12x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.12x|\t|%-12.12x|\t|%-12.12x|\t|%-12.12x|\t|%-12.12x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width && Precision = 0____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.0x|\t|%012.0x|\t|%012.0x|\t|%012.0x|\t|%012.0x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.0x|\t|%012.0x|\t|%012.0x|\t|%012.0x|\t|%012.0x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width && Precision = 1____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.1x|\t|%012.1x|\t|%012.1x|\t|%012.1x|\t|%012.1x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.1x|\t|%012.1x|\t|%012.1x|\t|%012.1x|\t|%012.1x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width && Precision = 6____________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.6x|\t|%012.6x|\t|%012.6x|\t|%012.6x|\t|%012.6x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.6x|\t|%012.6x|\t|%012.6x|\t|%012.6x|\t|%012.6x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width &&  Precision = 12___________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.12x|\t|%012.12x|\t|%012.12x|\t|%012.12x|\t|%012.12x|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.12x|\t|%012.12x|\t|%012.12x|\t|%012.12x|\t|%012.12x|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

/*    printf("\n/!\\ UNDEFINED BEHAVIOR = flag +\n");
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.0x|\t|%+-12.0x|\t|%-+12.0x|\t|%+-12.0x|\t|%+-12.0x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+12.0x|\t|%+12.0x|\t|%+12.0x|\t|%+12.0x|\t|%+12.0x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.1x|\t|%+-012.1x|\t|%-+012.1x|\t|%+-012.1x|\t|%+-012.1x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.1x|\t|%+012.1x|\t|%+012.1x|\t|%+012.1x|\t|%+012.1x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.6x|\t|%+-12.6x|\t|%-+12.6x|\t|%+-12.6x|\t|%+-12.6x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+12.6x|\t|%+12.6x|\t|%+12.6x|\t|%+12.6x|\t|%+12.6x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.12x|\t|%+-12.12x|\t|%-+12.12x|\t|%+-12.12x|\t|%+-12.12x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+12.12x|\t|%+12.12x|\t|%+12.12x|\t|%+12.12x|\t|%+12.12x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.0x|\t|%+-012.0x|\t|%-+012.0x|\t|%+-012.0x|\t|%+-012.0x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.0x|\t|%+012.0x|\t|%+012.0x|\t|%+012.0x|\t|%+012.0x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.1x|\t|%+-012.1x|\t|%-+012.1x|\t|%+-012.1x|\t|%+-012.1x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.1x|\t|%+012.1x|\t|%+012.1x|\t|%+012.1x|\t|%+012.1x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.6x|\t|%+-012.6x|\t|%-+012.6x|\t|%+-012.6x|\t|%+-012.6x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.6x|\t|%+012.6x|\t|%+012.6x|\t|%+012.6x|\t|%+012.6x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.12x|\t|%+-012.12x|\t|%-+012.12x|\t|%+-012.12x|\t|%+-012.12x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.12x|\t|%+012.12x|\t|%+012.12x|\t|%+012.12x|\t|%+012.12x|\n", pos, neg, z, u_max, min);
*/
    printf("\n/!\\ UNDEFINED BEHAVIOR = flag - && 0width\n");
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.0x|\t|%-012.0x|\t|%-012.0x|\t|%-012.0x|\t|%-012.0x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.1x|\t|%-012.1x|\t|%-012.1x|\t|%-012.1x|\t|%-012.1x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.6x|\t|%-012.6x|\t|%-012.6x|\t|%-012.6x|\t|%-012.6x|\n", pos, neg, z, u_max, min);
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.12x|\t|%-012.12x|\t|%-012.12x|\t|%-012.12x|\t|%-012.12x|\n", pos, neg, z, u_max, min);

    
    

    printf("\n***************\nFORMAT X-MAJ\n***************\n\n");
   
    printf(">> Precision = 0______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.0X|\t|%12.0X|\t|%12.0X|\t|%12.0X|\t|%12.0X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.0X|\t|%12.0X|\t|%12.0X|\t|%12.0X|\t|%12.0X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.0X|\t|%-12.0X|\t|%-12.0X|\t|%-12.0X|\t|%-12.0X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.0X|\t|%-12.0X|\t|%-12.0X|\t|%-12.0X|\t|%-12.0X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> Precision = 1______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.1X|\t|%12.1X|\t|%12.1X|\t|%12.1X|\t|%12.1X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.1X|\t|%12.1X|\t|%12.1X|\t|%12.1X|\t|%12.1X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.1X|\t|%-12.1X|\t|%-12.1X|\t|%-12.1X|\t|%-12.1X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.1X|\t|%-12.1X|\t|%-12.1X|\t|%-12.1X|\t|%-12.1X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> Precision = 6______________________________________________________________________________________________\n");
    ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.6X|\t|%12.6X|\t|%12.6X|\t|%12.6X|\t|%12.6X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.6X|\t|%12.6X|\t|%12.6X|\t|%12.6X|\t|%12.6X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.6X|\t|%-12.6X|\t|%-12.6X|\t|%-12.6X|\t|%-12.6X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.6X|\t|%-12.6X|\t|%-12.6X|\t|%-12.6X|\t|%-12.6X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> Precision = 12______________________________________________________________________________________________\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%12.12X|\t|%12.12X|\t|%12.12X|\t|%12.12X|\t|%12.12X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%12.12X|\t|%12.12X|\t|%12.12X|\t|%12.12X|\t|%12.12X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-12.12X|\t|%-12.12X|\t|%-12.12X|\t|%-12.12X|\t|%-12.12X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[flag -]\t|%-12.12X|\t|%-12.12X|\t|%-12.12X|\t|%-12.12X|\t|%-12.12X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width && Precision = 0____________________________________________________________________________________\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.0X|\t|%012.0X|\t|%012.0X|\t|%012.0X|\t|%012.0X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.0X|\t|%012.0X|\t|%012.0X|\t|%012.0X|\t|%012.0X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width && Precision = 1____________________________________________________________________________________\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.1X|\t|%012.1X|\t|%012.1X|\t|%012.1X|\t|%012.1X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.1X|\t|%012.1X|\t|%012.1X|\t|%012.1X|\t|%012.1X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width && Precision = 6____________________________________________________________________________________\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.6X|\t|%012.6X|\t|%012.6X|\t|%012.6X|\t|%012.6X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.6X|\t|%012.6X|\t|%012.6X|\t|%012.6X|\t|%012.6X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

    printf(">> 0width &&  Precision = 12___________________________________________________________________________________\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[no flag]\t|%012.12X|\t|%012.12X|\t|%012.12X|\t|%012.12X|\t|%012.12X|\n", pos, neg, z, u_max, min);
    ret = printf("VR_PRINTF\t[no flag]\t|%012.12X|\t|%012.12X|\t|%012.12X|\t|%012.12X|\t|%012.12X|\n", pos, neg, z, u_max, min);
	color(ret, ret2);
	printf("PRINTF = %d,\t FT_PRINTF = %d\n", ret, ret2);
	reset();

 /*   printf("\n/!\\ UNDEFINED BEHAVIOR = flag +\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.0X|\t|%+-12.0X|\t|%-+12.0X|\t|%+-12.0X|\t|%+-12.0X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+12.0X|\t|%+12.0X|\t|%+12.0X|\t|%+12.0X|\t|%+12.0X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.1X|\t|%+-012.1X|\t|%-+012.1X|\t|%+-012.1X|\t|%+-012.1X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.1X|\t|%+012.1X|\t|%+012.1X|\t|%+012.1X|\t|%+012.1X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.6X|\t|%+-12.6X|\t|%-+12.6X|\t|%+-12.6X|\t|%+-12.6X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+12.6X|\t|%+12.6X|\t|%+12.6X|\t|%+12.6X|\t|%+12.6X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-12.12X|\t|%+-12.12X|\t|%-+12.12X|\t|%+-12.12X|\t|%+-12.12X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+12.12X|\t|%+12.12X|\t|%+12.12X|\t|%+12.12X|\t|%+12.12X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.0X|\t|%+-012.0X|\t|%-+012.0X|\t|%+-012.0X|\t|%+-012.0X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.0X|\t|%+012.0X|\t|%+012.0X|\t|%+012.0X|\t|%+012.0X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.1X|\t|%+-012.1X|\t|%-+012.1X|\t|%+-012.1X|\t|%+-012.1X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.1X|\t|%+012.1X|\t|%+012.1X|\t|%+012.1X|\t|%+012.1X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.6X|\t|%+-012.6X|\t|%-+012.6X|\t|%+-012.6X|\t|%+-012.6X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.6X|\t|%+012.6X|\t|%+012.6X|\t|%+012.6X|\t|%+012.6X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +-]\t|%+-012.12X|\t|%+-012.12X|\t|%-+012.12X|\t|%+-012.12X|\t|%+-012.12X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag +]\t|%+012.12X|\t|%+012.12X|\t|%+012.12X|\t|%+012.12X|\t|%+012.12X|\n", pos, neg, z, u_max, min);
*/
    printf("\n/!\\ UNDEFINED BEHAVIOR = flag - && 0width\n");
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.0X|\t|%-012.0X|\t|%-012.0X|\t|%-012.0X|\t|%-012.0X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.1X|\t|%-012.1X|\t|%-012.1X|\t|%-012.1X|\t|%-012.1X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.6X|\t|%-012.6X|\t|%-012.6X|\t|%-012.6X|\t|%-012.6X|\n", pos, neg, z, u_max, min);
    ret2 = ret2 = ft_printf("MY_PRINTF\t[flag -]\t|%-012.12X|\t|%-012.12X|\t|%-012.12X|\t|%-012.12X|\t|%-012.12X|\n", pos, neg, z, u_max, min);

}
