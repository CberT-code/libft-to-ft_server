
int test2(void)
{
	int i;

	i = 0;
	if (!(i == 1))
		return (-1);
	return (1);
}

int		ft_test(void)
{
	test2();
	return (1);
}
int		main(void)
{
	printf("%d\n", ft_test());
	return (0);
}
