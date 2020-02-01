/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:46:49 by cbertola          #+#    #+#             */
/*   Updated: 2019/11/30 14:47:12 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <libc.h>
#include <ctype.h>

int		main(void)
{
	printf("FT_STRLEN\n");
	printf("%d\n\n", ft_strlen("test"));

	printf("---------------------------------------------------------\n");
	printf("FT_STRNCMP\n");
	printf("%d\n", strncmp("test", "tast", 4));
	printf("%d\n\n", ft_strncmp("test", "tast", 4));

	printf("FT_STRNCMP\n");
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n\n", ft_strncmp("test\200", "test\0", 6));

	printf("%d\n", strncmp("test", "test", 6));
	printf("%d\n\n", ft_strncmp("test", "test", 6));

	printf("%d\n", strncmp("te", "tast", 4));
	printf("%d\n\n", ft_strncmp("te", "tast", 4));

	printf("%d\n", strncmp("test", "t", 4));
	printf("%d\n\n", ft_strncmp("test", "t", 4));

	printf("%d\n", strncmp("t", "t", 4));
	printf("%d\n\n", ft_strncmp("t", "t", 4));

	printf("%d\n", strncmp("", "", 4));
	printf("%d\n\n", ft_strncmp("", "", 4));

	printf("%d\n", strncmp("", "tast", 4));
	printf("%d\n\n", ft_strncmp("", "tast", 4));

	printf("%d\n", strncmp("test", "", 4));
	printf("%d\n\n", ft_strncmp("test", "", 4));

	printf("---------------------------------------------------------\n");
	char tab[5];
	printf("FT_STRLCPY\n\n");
	printf("DST && SRC && DSTISIZE = 5\n");
	printf("%lu\n", strlcpy(tab, "test", 5));
	printf("%s\n\n", tab);
	printf("%lu\n", ft_strlcpy(tab, "test", 5));
	printf("%s\n\n", tab);

	printf("DST && DSTSIZE = 5 SRC= 7\n");
	printf("%lu\n", strlcpy(tab, "tester", 5));
	printf("%s\n\n", tab);
	printf("%lu\n", ft_strlcpy(tab, "tester", 5));
	printf("%s\n\n", tab);

	printf("DST = 5 SRC && DSTSIZE = 4\n");
	printf("%lu\n", strlcpy(tab, "tas", 4));
	printf("%s\n\n", tab);
	printf("%lu\n", ft_strlcpy(tab, "tas", 4));
	printf("%s\n\n", tab);

	printf("DST = 5 SRC = 6 DESTSIZE = 4 \n");
	printf("%lu\n", strlcpy(tab, "tester", 4));
	printf("%s\n\n", tab);
	printf("%lu\n", ft_strlcpy(tab, "tester", 4));
	printf("%s\n\n", tab);

	printf("DST = 5 SRC = 3 DESTSIZE = 4 \n");
	printf("%lu\n", strlcpy(tab, "te", 4));
	printf("%s\n\n", tab);
	printf("%lu\n", ft_strlcpy(tab, "te", 4));
	printf("%s\n\n", tab);

	printf("Si DESTSIZE > DST ERROR\n");

	printf("--------------------------------------------------------\n");
	printf("FT_STRCHR\n\n");
	printf("Recherche n dans bonjour\n");
	printf("%s\n", strchr("bonjour", 'n'));
	printf("%s\n", ft_strchr("bonjour", 'n'));

	printf("Recherche \\0 dans bonjour\n");
	printf("%s\n", strchr("bonjour", '\0'));
	printf("%s\n", ft_strchr("bonjour", '\0'));

	printf("Recherche q dans bonjour\n");
	printf("%s\n", strchr("bonjour", 'q'));
	printf("%s\n", ft_strchr("bonjour", 'q'));

	printf("--------------------------------------------------------\n");
	printf("FT_STRRCHR\n\n");
	printf("Recherche n dans bonjour\n");
	printf("%s\n", strrchr("bonjour", 'n'));
	printf("%s\n", ft_strrchr("bonjour", 'n'));

	printf("Recherche \\0 dans bonjour\n");
	printf("%s\n", strrchr("bonjour", '\0'));
	printf("%s\n", ft_strrchr("bonjour", '\0'));

	printf("Recherche q dans bonjour\n");
	printf("%s\n", strrchr("bonjour", 'q'));
	printf("%s\n", ft_strrchr("bonjour", 'q'));

	printf("--------------------------------------------------------\n");
	char tab2[10] = "test";
	printf("FT_STRLCAT\n\n");
	printf("DST[10] = test SRC = test DSTSIZE = 8 \n");
	printf("%lu\n", strlcat(tab2, "test", 10));
	printf("%s\n\n", tab2);
	char tab6[10] = "test";
	printf("%lu\n", ft_strlcat(tab6, "test", 10));
	printf("%s\n\n", tab6);

	char tab3[8] = "test";
	printf("DST[8] = test SRC = tester DSTSIZE = 8 \n");
	printf("%lu\n", strlcat(tab3, "tester", 8));
	printf("%s\n\n", tab3);
	char tab7[8] = "test";
	printf("%lu\n", ft_strlcat(tab7, "tester", 8));
	printf("%s\n\n", tab7);

	char tab4[8] = "test";
	printf("DST[8] = test SRC = tester DSTSIZE = 6\n");
	printf("%lu\n", strlcat(tab4, "tester", 6));
	printf("%s\n\n", tab4);
	char tab8[8] = "test";
	printf("%lu\n", ft_strlcat(tab8, "tester", 6));
	printf("%s\n\n", tab8);

	char tab5[8] = "test";
	printf("DST[8] = test SRC = t DSTSIZE = 8\n");
	printf("%lu\n", strlcat(tab5, "t", 8));
	printf("%s\n\n", tab5);
	char tab9[8] = "test";
	printf("%lu\n", ft_strlcat(tab9, "t", 8));
	printf("%s\n\n", tab9);
	
	char tab545[8] = "test";
	printf("DST[8] = test SRC = t DSTSIZE = 0\n");
	printf("%lu\n", strlcat(tab545, "t", 0));
	printf("%s\n\n", tab545);
	char tab945[8] = "test";
	printf("%lu\n", ft_strlcat(tab945, "t",0 ));
	printf("%s\n\n", tab945);

	char tab546[8] = "test";
	printf("DST[8] = test SRC = t DSTSIZE = 3\n");
	printf("%lu\n", strlcat(tab546, "t", 3));
	printf("%s\n\n", tab546);
	char tab946[8] = "test";
	printf("%lu\n", ft_strlcat(tab946, "t", 3));
	printf("%s\n\n", tab946);
	
	char tab547[18] = "test";
	printf("DST[18] = test SRC = titesofro DSTSIZE = 3\n");
	printf("%lu\n", strlcat(tab547, "titesofro", 3));
	printf("%s\n\n", tab547);
	char tab947[18] = "test";
	printf("%lu\n", ft_strlcat(tab947, "titesofro", 3));
	printf("%s\n\n", tab947);
	
	char tab548[18] = "test";
	printf("DST[18] = test SRC = titesofro DSTSIZE = 0\n");
	printf("%lu\n", strlcat(tab548, "titesofro", 0));
	printf("%s\n\n", tab548);
	char tab948[18] = "test";
	printf("%lu\n", ft_strlcat(tab948, "titesofro", 0));
	printf("%s\n\n", tab948);


	char *tab549;
	char *tab949;
	if (!(tab549 = (char *)malloc(sizeof(*tab549) * 15)))
		return (0);
	if (!(tab949 = (char *)malloc(sizeof(*tab949) * 15)))
		return (0);
	tab549[10] = 'a';
	tab949[10] = 'a';
	memset(tab549, 'r', 15);
	printf("DST[18] = test SRC = titesofro DSTSIZE = 0\n");
	printf("%lu\n", strlcat(tab549, "lorem ipsum dolor sit amet", 5));
	printf("%s\n\n", tab549);
	memset(tab949, 'r', 15);
	printf("%lu\n", ft_strlcat(tab949, "lorem ipsum dolor sit amet", 5));
	printf("%s\n\n", tab949);


	printf("-------------------------------------------------------\n");
	printf("FT_STRNSTR\n\n");
	printf("bonjour je suis la. RECHERCHE = je LEN = 20\n");
	printf("%s\n", strnstr("bonjour je suis la", "je", 20));
	printf("%s\n\n", ft_strnstr("bonjour je suis la", "je", 20));

	printf("bonjour je suis la. RECHERCHE = je LEN = 1\n");
	printf("%s\n", strnstr("bonjour je suis la", "je", 1));
	printf("%s\n\n", ft_strnstr("bonjour je suis la", "je", 1));

	printf("bonjour je suis la. RECHERCHE = je LEN = 4\n");
	printf("%s\n", strnstr("bonjour je suis la", "je", 4));
	printf("%s\n\n", ft_strnstr("bonjour je suis la", "je", 4));

	printf("bonjour je suis la. RECHERCHE = NULL\n");
	printf("%s\n", strnstr("bonjour je suis la", "", 3));
	printf("%s\n\n", ft_strnstr("bonjour je suis la", "", 3));

	printf("lorem ipsum dolor sit amet Recherche DOLOR\n");
	printf("%s\n", strnstr("lorem ipsum dolor sit amet","dolor",15 ));
	printf("%s\n\n", ft_strnstr("lorem ipsum dolor sit amet","dolor",15 ));

	printf("Recherche = p LEN = 2\n");
	printf("%s\n", strnstr("", "p", 2));
	printf("%s\n\n", ft_strnstr("", "p", 2));

	printf("bonjour je suis la. Recherche = ji\n");
	printf("%s\n", strnstr("bonjour je suis la", "ji", 3));
	printf("%s\n\n", ft_strnstr("bonjour je suis la", "ji", 3));


	printf("-------------------------------------------------------\n");
	printf("FT_ISALPHA\n\n");
	printf("A\n");
	printf("%d\n", isalpha('A'));
	printf("%d\n\n", ft_isalpha('A'));

	printf("O\n");
	printf("%d\n", isalpha('O'));
	printf("%d\n\n", ft_isalpha('O'));
	
	printf("Z\n");
	printf("%d\n", isalpha('Z'));
	printf("%d\n\n", ft_isalpha('Z'));

	printf("a\n");
	printf("%d\n", isalpha('a'));
	printf("%d\n\n", ft_isalpha('a'));

	printf("o\n");
	printf("%d\n", isalpha('o'));
	printf("%d\n\n", ft_isalpha('o'));

	printf("z\n");
	printf("%d\n", isalpha('z'));
	printf("%d\n\n", ft_isalpha('z'));
	
	printf("0\n");
	printf("%d\n", isalpha('0'));
	printf("%d\n\n", ft_isalpha('0'));

	printf("-------------------------------------------------------\n");
	printf("FT_ISDIGIT\n\n");
	printf("0\n");
	printf("%d\n", isdigit('0'));
	printf("%d\n\n", ft_isdigit('0'));

	printf("9\n");
	printf("%d\n", isdigit('9'));
	printf("%d\n\n", ft_isdigit('9'));

	printf("A\n");
	printf("%d\n", isdigit('A'));
	printf("%d\n\n", ft_isdigit('A'));

	printf("-------------------------------------------------------\n");
	printf("FT_ISALNUM\n\n");
	printf("A\n");
	printf("%d\n", isalnum('A'));
	printf("%d\n\n", ft_isalnum('A'));

	printf("O\n");
	printf("%d\n", isalnum('O'));
	printf("%d\n\n", ft_isalnum('O'));
	
	printf("Z\n");
	printf("%d\n", isalnum('Z'));
	printf("%d\n\n", ft_isalnum('Z'));

	printf("a\n");
	printf("%d\n", isalnum('a'));
	printf("%d\n\n", ft_isalnum('a'));

	printf("o\n");
	printf("%d\n", isalnum('o'));
	printf("%d\n\n", ft_isalnum('o'));

	printf("z\n");
	printf("%d\n", isalnum('z'));
	printf("%d\n\n", ft_isalnum('z'));
	
	printf("0\n");
	printf("%d\n", isalnum('0'));
	printf("%d\n\n", ft_isalnum('0'));

	printf("9\n");
	printf("%d\n", isalnum('9'));
	printf("%d\n\n", ft_isalnum('9'));

	printf("SPC\n");
	printf("%d\n", isalnum(' '));
	printf("%d\n\n", ft_isalnum(' '));

	printf("-------------------------------------------------------\n");
	printf("FT_isascii\n\n");
	printf("0\n");
	printf("%d\n", isascii(0));
	printf("%d\n\n", ft_isascii(0));

	printf("127\n");
	printf("%d\n", isascii(127));
	printf("%d\n\n", ft_isascii(127));
	
	printf("40\n");
	printf("%d\n", isascii(40));
	printf("%d\n\n", ft_isascii(40));
	
	printf("178\n");
	printf("%d\n", isascii(178));
	printf("%d\n\n", ft_isascii(178));
	
	printf("-------------------------------------------------------\n");
	printf("FT_ISPRINT\n\n");
	printf("0\n");
	printf("%d\n", isprint(0));
	printf("%d\n\n", ft_isprint(0));

	printf("126\n");
	printf("%d\n", isprint(126));
	printf("%d\n\n", ft_isprint(126));
	
	printf("40\n");
	printf("%d\n", isprint(40));
	printf("%d\n\n", ft_isprint(40));
	
	printf("127\n");
	printf("%d\n", isprint(127));
	printf("%d\n\n", ft_isprint(127));
	
	printf("-------------------------------------------------------\n");
	printf("FT_toupper\n\n");
	printf("A\n");
	printf("%d\n", toupper('A'));
	printf("%d\n\n", ft_toupper('A'));

	printf("a\n");
	printf("%d\n", toupper('a'));
	printf("%d\n\n", ft_toupper('a'));
	
	printf("z\n");
	printf("%d\n", toupper('z'));
	printf("%d\n\n", ft_toupper('z'));
	
	printf("Z\n");
	printf("%d\n", toupper('Z'));
	printf("%d\n\n", ft_toupper('Z'));
	
	printf("45\n");
	printf("%d\n", toupper(45));
	printf("%d\n\n", ft_toupper(45));
	
	printf("-------------------------------------------------------\n");
	printf("FT_TOLOWER\n\n");
	printf("A\n");
	printf("%d\n", tolower('A'));
	printf("%d\n\n", ft_tolower('A'));

	printf("a\n");
	printf("%d\n", tolower('a'));
	printf("%d\n\n", ft_tolower('a'));
	
	printf("z\n");
	printf("%d\n", tolower('z'));
	printf("%d\n\n", ft_tolower('z'));
	
	printf("Z\n");
	printf("%d\n", tolower('Z'));
	printf("%d\n\n", ft_tolower('Z'));
	
	printf("45\n");
	printf("%d\n", tolower(45));
	printf("%d\n\n", ft_tolower(45));

	printf("-------------------------------------------------------\n");
	printf("FT_MEMSET\n\n");
	printf("c\n");

	char tab20[20];
	char tab21[20];
	memset((void *)tab20,'c', 2);
	printf("%s\n", tab20);
	ft_memset((void *)tab21,'c',2);
	printf("%s\n", tab21);

	printf("-------------------------------------------------------\n");
	printf("FT_BZERO\n\n");
	printf("Affiche des \\0 \n");

	char tab22[8];
	char tab23[8];
	bzero((void *)tab22, 2);
	printf("%s\n", tab22);
	ft_bzero((void *)tab23, 2);
	printf("%s\n", tab23);

	printf("-------------------------------------------------------\n");
	printf("memcpy\n\n");
	printf("tab = 8 SRC = test limit = 3 \n");
	char tab24[8];
	char tab25[8]="test";
	memcpy((void *)tab24, (void *)tab25, 3);
	printf("%s\n\n", tab24);
	
	printf("tab = 8 SRC = test limit = 6 \n");
	char tab26[8];
	char tab27[8]="test";
	memcpy((void *)tab26, (void *)tab27, 6);
	printf("%s\n\n", tab26);
	
	printf("tab = 8 SRC = testtest limit = 8 \n");
	char tab28[8];
	char tab29[8]="testpopo";
	memcpy((void *)tab28, (void *)tab29, 8);
	printf("%s\n\n", tab28);
	
	printf("-------------------------------------------------------\n");
	printf("FT_MEMCPY\n\n");
	printf("tab = 8 SRC = test limit = 3 \n");
	char tab34[8];
	char tab35[8]="test";
	ft_memcpy((void *)tab34, (void *)tab35, 3);
	printf("%s\n\n", tab34);
	
	printf("tab = 8 SRC = test limit = 6 \n");
	char tab36[8];
	char tab37[8]="test";
	ft_memcpy((void *)tab36, (void *)tab37, 6);
	printf("%s\n\n", tab36);
	
	printf("tab = 8 SRC = testtest limit = 8 \n");
	char tab38[8];
	char tab39[8]="testpopo";
	ft_memcpy((void *)tab38, (void *)tab39, 8);
	printf("%s\n\n", tab38);

	printf("tabc = 8 SRC = testtest limit = 8 \n");
	char tabc38[8];
	char tabc39[8]="Ω";
	ft_memcpy((void *)tabc38, (void *)tabc39, 8);
	printf("%s\n\n", tabc38);

	printf("-------------------------------------------------------\n");
	printf("MEMCCPY\n\n");
	char tab44[8];
	char tab45[8]="test";
	memccpy((void *)tab44, (void *)tab45,117, 5);
	printf("%s\n\n", tab44);
	
	char tab46[8];
	char tab47[8]="test";
	char *s;
	s = memccpy((void *)tab46, (void *)tab47,115, 6);
	printf("%s\n",s);
	printf("%s\n\n", tab46);
	
	char tab48[8];
	char tab49[8]="testpopo";
	memccpy((void *)tab48, (void *)tab49,115, 8);
	printf("%s\n\n", tab48);

	printf("-------------------------------------------------------\n");
	printf("ft_memccpy\n\n");
	char tab54[8];
	char tab55[8]="test";
	ft_memccpy((void *)tab54, (void *)tab55,117, 5);
	printf("%s\n\n", tab54);

	char tab56[8];
	char tab57[8]="test";
	char *s2;
	s2 = ft_memccpy((void *)tab56, (void *)tab57,115, 6);
	printf("%s\n",s2);
	printf("%s\n\n", tab56);

	char tab58[8];
	char tab59[8]="testpopo";
	ft_memccpy((void *)tab58, (void *)tab59,115, 8);
	printf("%s\n\n", tab58);

	printf("-------------------------------------------------------\n");
	printf("MEMMOVE\n\n");
	printf("tab = 8 SRC = test limit = 3 \n");
	char tab64[8] = "ab";
	char tab65[8] = "test";
	memmove((void *)tab64, (void *)tab65, 3);
	printf("%s\n\n", tab64);

	printf("tab = 8 SRC = test limit = 6 \n");
	char tab66[8] = "abcd";
	char tab67[8] = "test";
	memmove((void *)tab66, (void *)tab67, 6);
	printf("%s\n\n", tab66);

	printf("tab = 8 SRC = testpopo limit = 8 \n");
	char tab68[8] = "abcdef";
	char tab69[8] = "testpopo";
	memmove((void *)tab68, (void *)tab69, 8);
	printf("%s\n\n", tab68);
	
	printf("tab = 8 SRC = testtest limit = 8 \n");
	char tab61[8] = "abcdefgh";
	char tab62[8] = "testpop";
	memmove((void *)tab61, (void *)tab62, 8);
	printf("%s\n\n", tab61);

	printf("-------------------------------------------------------\n");
	printf("ft_memmove\n\n");
	printf("tab = 8 SRC = test limit = 3 \n");
	char tab74[8] = "ab";
	char tab75[8] = "test";
	ft_memmove((void *)tab74, (void *)tab75, 3);
	printf("%s\n\n", tab74);

	printf("tab = 8 SRC = test limit = 6 \n");
	char tab76[8] = "abcd";
	char tab77[8] = "test";
	ft_memmove((void *)tab76, (void *)tab77, 6);
	printf("%s\n\n", tab76);

	printf("tab = 8 SRC = testpopo limit = 8 \n");
	char tab78[8] = "abcdef";
	char tab79[8] = "testpopo";
	ft_memmove((void *)tab78, (void *)tab79, 8);
	printf("%s\n\n", tab78);
	
	printf("tab = 8 SRC = testtest limit = 8 \n");
	char tab71[8] = "abcdefgh";
	char tab72[8] = "testpop";
	ft_memmove((void *)tab71, (void *)tab72, 8);
	printf("%s\n\n", tab71);

	printf("-------------------------------------------------------\n");
	printf("memchr\n\n");
	printf("tab = testpopo, recherche : o = 111 limit = 8 \n");
	char tabb1[8] = "testpopo";
	printf("%s\n\n", memchr((void *)tabb1, 111, 8));

	printf("tab = testpopa, recherche : a = 97 limit = 8 \n");
	char tabb2[8] = "testpopa";
	printf("%s\n\n", memchr((void *)tabb2, 97, 8));

	printf("tab = testpopa, recherche : a = 97 limit = 6 \n");
	char tabb3[8] = "testpopa";
	printf("%s\n\n", memchr((void *)tabb3, 97, 6));

	printf("-------------------------------------------------------\n");
	printf("ft_memchr\n\n");
	printf("tab = testpopo, recherche : o = 111 limit = 8 \n");
	char tabb4[8] = "testpopo";
	printf("%s\n\n", ft_memchr((void *)tabb4, 111, 8));

	printf("tab = testpopa, recherche : a = 97 limit = 8 \n");
	char tabb5[8] = "testpopa";
	printf("%s\n\n", ft_memchr((void *)tabb5, 97, 8));

	printf("tab = testpopa, recherche : a = 97 limit = 6 \n");
	char tabb6[8] = "testpopa";
	printf("%s\n\n", ft_memchr((void *)tabb6, 97, 6));

	printf("-------------------------------------------------------\n");
	printf("memcmp\n\n");
	printf("tab = testpopo, tab = testpapa limit = 8 \n");
	char tabb10[8] = "testpopo";
	char tabb11[8] = "testpapa";
	printf("%d\n\n", memcmp((void *)tabb10, (void *)tabb11, 8));

	printf("tab = testpopo, tab = testpapa limit = 3 \n");
	char tabb12[8] = "testpopo";
	char tabb13[8] = "testpapa";
	printf("%d\n\n", memcmp((void *)tabb12, (void *)tabb13, 3));

	printf("tab = testpapa, tab = testpopo limit = 8 \n");
	char tabb14[8] = "testpapa";
	char tabb15[8] = "testpopo";
	printf("%d\n\n", memcmp((void *)tabb14, (void *)tabb15, 8));

	printf("-------------------------------------------------------\n");
	printf("ft_memcmp\n\n");
	printf("tab = testpopo, tab = testpapa limit = 8 \n");
	char tabb16[8] = "testpopo";
	char tabb17[8] = "testpapa";
	printf("%d\n\n", ft_memcmp((void *)tabb16, (void *)tabb17, 8));

	printf("tab = testpopo, tab = testpapa limit = 3 \n");
	char tabb18[8] = "testpopo";
	char tabb19[8] = "testpapa";
	printf("%d\n\n", ft_memcmp((void *)tabb18, (void *)tabb19, 3));

	printf("tab = testpapa, tab = testpopo limit = 8 \n");
	char tabb20[8] = "testpapa";
	char tabb21[8] = "testpopo";
	printf("%d\n\n", ft_memcmp((void *)tabb20, (void *)tabb21, 8));

	printf("-------------------------------------------------------\n");
	printf("ATOI\n\n");
	printf("tab = test12 \n");
	char tabbb1[8] = "tes12";
	printf("%d\n\n", atoi(tabbb1));

	printf("tab = (space)test12 \n");
	char tabbb2[8] = " tes12";
	printf("%d\n\n", atoi(tabbb2));

	printf("tab = +-test12 \n");
	char tabbb3[8] = "+-tes12";
	printf("%d\n\n", atoi(tabbb3));

	printf("tab = +--tes12 \n");
	char tabbb4[8] = "+--tes12";
	printf("%d\n\n", atoi(tabbb4));

	printf("tab = +-12 \n");
	char tabbb5[8] = "+-12";
	printf("%d\n\n", atoi(tabbb5));

	printf("tab = -12 \n");
	char tabbb6[8] = "-12";
	printf("%d\n\n", atoi(tabbb6));

	printf("tab = 12 \n");
	char tabbb7[8] = "12";
	printf("%d\n\n", atoi(tabbb7));

	printf("tab = 12te \n");
	char tabbb8[8] = "12te";
	printf("%d\n\n", atoi(tabbb8));

	printf("tab = (space)12 \n");
	char tabbb9[8] = " 12";
	printf("%d\n\n", atoi(tabbb9));

	printf("tab = (space --12) \n");
	char tabbb10[8] = " --tes12";
	printf("%d\n\n", atoi(tabbb10));

	printf("tab = (space space-12) \n");
	char tabbb11[8] = "  -tes12";
	printf("%d\n\n", atoi(tabbb11));

	printf("-------------------------------------------------------\n");
	printf("ft_atoi\n\n");
	printf("tab = test12 \n");
	char tabbb112[8] = "tes12";
	printf("%d\n\n", ft_atoi(tabbb112));

	printf("tab = (space)test12 \n");
	char tabbb12[8] = " tes12";
	printf("%d\n\n", ft_atoi(tabbb12));

	printf("tab = +-test12 \n");
	char tabbb13[8] = "+-tes12";
	printf("%d\n\n", ft_atoi(tabbb13));

	printf("tab = +--tes12 \n");
	char tabbb14[8] = "+--tes12";
	printf("%d\n\n", ft_atoi(tabbb14));

	printf("tab = +-12 \n");
	char tabbb15[8] = "+-12";
	printf("%d\n\n", ft_atoi(tabbb15));

	printf("tab = -12 \n");
	char tabbb16[8] = "-12";
	printf("%d\n\n", ft_atoi(tabbb16));

	printf("tab = 12 \n");
	char tabbb17[8] = "12";
	printf("%d\n\n", ft_atoi(tabbb17));

	printf("tab = 12te \n");
	char tabbb18[8] = "12te";
	printf("%d\n\n", ft_atoi(tabbb18));

	printf("tab = (space)12 \n");
	char tabbb19[8] = " 12";
	printf("%d\n\n", ft_atoi(tabbb19));

	printf("tab = (space --12) \n");
	char tabbb110[8] = " --tes12";
	printf("%d\n\n", ft_atoi(tabbb110));

	printf("tab = (space space-12) \n");
	char tabbb111[8] = "  -tes12";
	printf("%d\n\n", ft_atoi(tabbb111));
	
	printf("-------------------------------------------------------\n");
	printf("ft_strdup\n\n");
	printf("%s\n",strdup("testcoucou"));
	printf("%s\n\n\n\n",ft_strdup("testcoucou"));
	printf("-------------------------------------------------------\n");
	printf("            PART2\n\n");
	printf("-------------------------------------------------------\n\n\n\n");
	printf("SUBSTR \n");

	printf(" CHAINE = 6, 4, 2\n");
	printf("%s\n\n",ft_substr("testco", 4, 2));

	printf(" CHAINE = 6, 4, 2+1\n");
	printf("%s\n\n",ft_substr("testco", 4, 3));

	printf(" CHAINE = 6, 4, 6\n");
	printf("%s\n\n",ft_substr("testco", 4, 6));
	
	printf(" CHAINE = 6, 0, 2\n");
	printf("%s\n\n",ft_substr("testco", 0, 2));

	printf(" CHAINE = 6, 4, 0\n");
	printf("%s\n\n",ft_substr("testco", 4, 0));
	
	printf(" CHAINE = 0, 4, 2\n");
	printf("%s\n\n",ft_substr("", 4, 2));

	printf(" CHAINE = 6, 8, 2\n");
	printf("%s\n\n",ft_substr("testco", 8, 2));

	printf("-------------------------------------------------------\n");
	printf("STRJOIN \n");

	printf(" COUCOU + TEST\n");
	printf("%s\n\n",ft_strjoin("coucou","test"));

	printf(" COUCOU + \\\" \\\" \n");
	printf("%s\n\n",ft_strjoin("coucou",""));

	printf(" \\\" \\\" + TEST\n");
	printf("%s\n\n",ft_strjoin("","test"));

	printf("-------------------------------------------------------\n");
	printf("STRTRIM \n");

	printf(" TESTCOUCOUTEST && TEST\n");
	printf("%s\n\n",ft_strtrim("testcoucoutest","test"));

	printf(" TESTCOUCOUTEST && T\n");
	printf("%s\n\n",ft_strtrim("testcoucoutest","t"));

	printf(" TESTCOUCOUTEST && \n");
	printf("%s\n\n",ft_strtrim("testcoucoutest",""));

	printf(" && T\n");
	printf("%s\n\n",ft_strtrim("","t"));

	printf(" TESTCOUCOUTEST && Z\n");
	printf("%s\n\n",ft_strtrim("testcoucoutest","z"));

	printf("                &&  \n");
	printf("%s\n\n",ft_strjoin("        "," "));

	printf("-------------------------------------------------------\n");
	printf("PUTNBR \n");

	printf(" TESTCOUCOUTEST && TEST\n");
	ft_putnbr_fd(154658,1);

	printf("\n\n-------------------------------------------------------\n");
	printf("ft_itoa \n");

	printf("48578\n");
	printf("%s\n\n",ft_itoa(48578));

	printf("-48578\n");
	printf("%s\n\n",ft_itoa(-48578));

	printf(" 0\n");
	printf("%s\n\n",ft_itoa(0));
	
	printf("-0\n");
	printf("%s\n\n",ft_itoa(-0));

	printf("-10\n");
	printf("%s\n\n",ft_itoa(-10));

	printf("-2147483648\n");
	printf("%s\n\n",ft_itoa(-2147483648));

	printf("2147483647\n");
	printf("%s\n\n",ft_itoa(2147483647));








}
