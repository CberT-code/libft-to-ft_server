#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dst, char *src);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_read(int fd, void *buf, size_t nbyte);
size_t			ft_write(int fd, const void *buf, size_t nbyte);
char			*ft_strdup(const char *str);

void			check_ft_strlen()
{
	char 	*str;
	
	printf("\n\t FT_STRLEN -----------------------------\n");
	
	str = "";
	printf("str -> '%s'\n", str);
	printf("   strlen: %d\n", (int)strlen(str));
	printf("ft_strlen: %d\n\n", (int)ft_strlen(str));

	str = "abcdefghijklmnopqrstuvwxyz";
	printf("str -> '%s'\n", str);
	printf("   strlen: %d\n", (int)strlen(str));
	printf("ft_strlen: %d\n\n", (int)ft_strlen(str));

	str = "Ce test devrait fonctionner";
	printf("str -> '%s'\n", str);
	printf("   strlen: %d\n", (int)strlen(str));
	printf("ft_strlen: %d\n\n", (int)ft_strlen(str));

	str = "kprhwefigjwherlghijjengbhijlwhkjenglhijhs;kfdghljsd;hgbfhdslkjhgbdfshlkjghfbdshlkjghsdf";
	printf("str -> '%s'\n", str);
	printf("   strlen: %d\n", (int)strlen(str));
	printf("ft_strlen: %d\n\n", (int)ft_strlen(str));
	printf("\n\t\t ----- END -----\n\n");
}

void			check_ft_strcpy()
{
	char		*src_text;
	char		*dest_text;
	char		*src;
	char		*dest;
	char		*ft_src;
	char		*ft_dest;

	printf("\n\t\t ----- FT_STRCPY -----\n");
	src_text = "Bonsoir";
	dest_text = "A toute et a tous";
	printf("src -> '%s' : dest -> '%s'\n", src_text, dest_text);
	src = strdup(src_text);
	dest = strdup(dest_text);
	ft_src = strdup(src_text);
	ft_dest = strdup(dest_text);
	strcpy(dest, src);
	ft_strcpy(ft_dest, ft_src);
	printf("   strcpy: %s\nft_strcpy: %s\n\n", dest, ft_dest);

	src_text = "A toute et a tous";
	dest_text = "Bonsoir";
	printf("src -> '%s' : dest -> '%s'\n", src_text, dest_text);
	src = strdup(src_text);
	dest = strdup(dest_text);
	ft_src = strdup(src_text);
	ft_dest = strdup(dest_text);
	strcpy(dest, src);
	ft_strcpy(ft_dest, ft_src);
	printf("   strcpy: %s\nft_strcpy: %s\n\n", dest, ft_dest);

	src_text = "";
	dest_text = "Bonsoir";
	printf("src -> '%s' : dest -> '%s'\n", src_text, dest_text);
	src = strdup(src_text);
	dest = strdup(dest_text);
	ft_src = strdup(src_text);
	ft_dest = strdup(dest_text);
	strcpy(dest, src);
	ft_strcpy(ft_dest, ft_src);
	printf("   strcpy: %s\nft_strcpy: %s\n\n", dest, ft_dest);

	src_text = "Bonsoir";
	dest_text = "";
	printf("src -> '%s' : dest -> '%s'\n", src_text, dest_text);
	src = strdup(src_text);
	dest = strdup(dest_text);
	ft_src = strdup(src_text);
	ft_dest = strdup(dest_text);
	strcpy(dest, src);
	ft_strcpy(ft_dest, ft_src);
	printf("   strcpy: %s\nft_strcpy: %s\n\n", dest, ft_dest);
	printf("\n\t\t ----- END -----\n\n");
}

void			check_ft_strcmp()
{
	char		*s1;
	char		*s2;

	printf("\n\t\t ----- FT_STRCMP -----\n");
	s1 = "Bonsoir";
	s2 = "Bonsoir";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonsoir", "Bonsoir"));


	s1 = "Bonjoir";
	s2 = "Bonsoir";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonjoir", "Bonsoir"));

	s1 = "Bonso";
	s2 = "Bonsoir";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp(s1, s2));
	s1 = "Bonsoir";
	s2 = "Bonso";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp(s1, s2));

	s1 = "";
	s2 = "Bonsoir";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp(s1, s2));

	s1 = "Bonsoir";
	s2 = "";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp(s1, s2));

	s1 = "";
	s2 = "";
	printf("s1 -> '%s' : s2 -> '%s'\n", s1, s2);
	printf("   strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n\n", ft_strcmp(s1, s2));

	printf("\n\t\t ----- END -----\n\n");
}

void			ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void			check_ft_read()
{
	int			fd = open("text.txt", O_RDONLY);
	int			ft_fd = open("text.txt", O_RDONLY);
	int			ret;
	int			ft_ret;
	char		buffer[30];
	char		ft_buffer[30];
	int			value;

	printf("\n\t\t ----- FT_READ -----\n");

	value = 15;
	for (int i = 0; i < 3; i++)
	{
		ft_bzero(buffer, 30);
		ft_bzero(ft_buffer, 30);
		ret = read(fd, buffer, value);
		ft_ret = ft_read(ft_fd, ft_buffer, value);
		printf("   read: '%s' -> %d\n", buffer, ret);
		printf("ft_read: '%s' -> %d\n\n", ft_buffer, ft_ret);
		value += 5;
	}

	printf("---> error bad fd test\n");
	ft_bzero(buffer, 30);
	ft_bzero(ft_buffer, 30);
	errno = 0;
	ret = read(-1, buffer, 15);
	printf("   read: errno: %d %s -> %d\n", errno, strerror(errno), ret);
	printf("buffer: '%s'\n", buffer);
	errno = 0;
	ft_ret = ft_read(-1, ft_buffer, 15);
	printf("ft_read: errno: %d %s -> %d\n", errno, strerror(errno), ft_ret);
	printf("buffer: '%s'\n\n",ft_buffer);

	printf("---> error bad buffer test\n");
	ft_bzero(buffer, 30);
	ft_bzero(ft_buffer, 30);
	errno = 0;
	ret = read(fd, 250, 15);
	printf("   read: errno: %d %s -> %d\n", errno, strerror(errno), ret);
	printf("buffer: '%s'\n", buffer);
	errno = 0;
	ft_ret = ft_read(ft_fd, 250, 15);
	printf("ft_read: errno: %d %s -> %d\n", errno, strerror(errno), ft_ret);
	printf("buffer: '%s'\n\n",ft_buffer);

	close(fd);
	close(ft_fd);
	printf("\n\t\t ----- END -----\n\n");
}

void			check_ft_write()
{
	int ret;
	int ft_ret;
	char *str;

	printf("\n\t\t ----- FT_WRITE -----\n\n");
	str = "Bonsoir a toute et a tous";
	printf("string : '%s'\n", str);
	ret = write(1, str, ft_strlen(str));
	printf(":    write returned : %d\n", ret);
	ft_ret = ft_write(1, str, ft_strlen(str));
	printf(": ft_write returned : %d\n\n", ft_ret);

	str = "";
	printf("string : '%s'\n", str);
	ret = write(1, str, ft_strlen(str));
	printf(":    write returned : %d\n", ret);
	ft_ret = ft_write(1, str, ft_strlen(str));
	printf(": ft_write returned : %d\n\n", ft_ret);

	printf("--> Error with bad fd\n");	
	str = "Ceci est un test";
	printf("string : '%s'\n", str);
	errno = 0;
	ret = write(489, str, ft_strlen(str));
	printf(":    write returned : %d : %s -> %d\n", ret, strerror(errno), errno);
	errno = 0;	
	ft_ret = ft_write(489, str, ft_strlen(str));
	printf(": ft_write returned : %d : %s -> %d\n\n", ft_ret, strerror(errno), errno);
	
	printf("\n\t\t ----- END -----\n\n");
}


void			check_ft_strdup()
{
	printf("\n\t\t ----- FT_WRITE -----\n\n");

	char *text;

	text = "Bonsoir a toute et a tous";
	printf("original text : '%s'\n", text);
	char *str = strdup(text);
	char *ft_str = ft_strdup(text);
	printf("   write: '%s'\nft_write: '%s'\n", str, ft_str);
	free(str);
	free(ft_str);

	text = "";
	printf("original text : '%s'\n", text);
	str = strdup(text);
	ft_str = ft_strdup(text);
	printf("   write: '%s'\nft_write: '%s'\n", str, ft_str);
	free(str);
	free(ft_str);

	text = "Deuxieme test ca doit fonctionner :P";
	printf("original text : '%s'\n", text);
	str = strdup(text);
	ft_str = ft_strdup(text);
	printf("   write: '%s'\nft_write: '%s'\n", str, ft_str);
	free(str);
	free(ft_str);

	printf("\n\t\t ----- END -----\n");
}

int				main(int argc, char **argv)
{
	check_ft_read();
	check_ft_strcmp();
	check_ft_strcpy();
	check_ft_strdup();
	check_ft_strlen();
	check_ft_write();
	return (0);
}