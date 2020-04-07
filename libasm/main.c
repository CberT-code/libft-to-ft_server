/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:58 by thgermai          #+#    #+#             */
/*   Updated: 2020/04/07 20:22:47 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

/*
** Useful macros
*/
# define STRLEN(x)			printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)		printf("`%s`:`%s` = %d (%d)\n", a, b, ft_strcmp(a, b), strcmp(a, b));
# define WRITE(s, x)		printf("^%ld (`%s`:%ld)\n", ft_write(STDOUT_FILENO, s, x), s, x);
# define READ(b, x)			r = ft_read(STDIN_FILENO, buffer, x); printf("`%s`:%ld\n", buffer, r);
# define DUP(s)				tmp = ft_strdup(s); printf("`%s` (`%s`)\n", tmp, s); free(tmp); tmp = NULL;

/*
** Function prototypes
*/
int		ft_strlen(char const *str);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
char	*ft_strdup(char const *s1);

/*
** Start !
*/

void	test_ft_write()
{
	int			fd;
	char		buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 2));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'toto' '40'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 40));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, NULL, 6));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, NULL, 6));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(42, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(-1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(-1, "toto", 4));
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
	write(fd, "<unistd.h> toto", 15);
	ft_write(fd, "<libasm.h> toto", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %s\n", buffer);
	read(fd, buffer, 15);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void	test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;

	printf("\x1b[32mft_read:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 50);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	close(fd);
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
	ret = read(42, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(42, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\x1b[0m\n");
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void	test_ft_strcpy()
{
	char	dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, "qwertyuiop"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789abcdefg'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789abcdefg"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, "0123456789abcdefg"));
	// printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	// printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	// printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, NULL));
}

void	test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'qwertyuiop' 'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("qwertyuiop", "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("qwertyuiop", "qwertyuiop"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'qwertyuiop' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("qwertyuiop", ""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("qwertyuiop", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp("", "qwertyuiop"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'qwertyuioptest' 'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("qwertyuioptest", "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("qwertyuioptest", "qwertyuiop"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
	// printf("	\x1b[34m[7]\x1b[0m \x1b[36m'NULL' 'bbonjour'\x1b[0m\n");
	// printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	// printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp(NULL, "bbonjour"));
	// printf("	\x1b[34m[8]\x1b[0m \x1b[36m'NULL' 'NULL'\x1b[0m\n");
	// printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	// printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp(NULL, NULL));
	// printf("	\x1b[34m[9]\x1b[0m \x1b[36m'' 'NULL'\x1b[0m\n");
	// printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	// printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp("", NULL));
}

void	test_ft_strdup()
{
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("qwertyuiop"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("qwertyuiop"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789abcdefgh'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n",
								strdup("0123456789abcdefgh"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n",
								ft_strdup("0123456789abcdefgh"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(NULL));
}

int		main(void)
{
	test_ft_write();
	printf("Appuyez sur [entree] pour continuer...\n");
	getchar();
    test_ft_read();
	printf("Appuyez sur [entree] pour continuer...\n");
	getchar();
    test_ft_strcpy();
	printf("Appuyez sur [entree] pour continuer...\n");
	getchar();
    test_ft_strcmp();
	printf("Appuyez sur [entree] pour continuer...\n");
	getchar();
     test_ft_strdup();
	printf("Appuyez sur [entree] pour continuer...\n");
	getchar();
	return (0);
}
