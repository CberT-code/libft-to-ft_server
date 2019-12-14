
int			ft_count_char_int(long int nb, int base)
{
	int			count;
	long int	i;
	
	if (base == 0)
		return (-1);
	count = 0;
	i = nb;
	if (i <= 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= base;
		count++;
	}
	return (count);
}
