/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarme_rdv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <#H42MAIL>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:04:35 by cyrillebe         #+#    #+#             */
/*   Updated: 2020/02/21 12:00:51 by cyrillebe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		check_date(int min, int max)
{
	int			fd;
	char		*line;
	char		*search;

	search = "role=\"button\">";
	fd = open("recup.txt",O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		search = &line[ft_isfind(line, '>') + 1];
		search = ft_strjoin(ft_substr(search, 3, 2), ft_substr(search, 0, 2));
		if (ft_atoi(search) > min && ft_atoi(search) < max)
			return (1);
	}
	return (0);
}

void		recup_html()
{
	char		*requete;

	requete = "curl https://rendezvousonline.fr/recherche/Carte+Nationale+d%27Identit%C3%A9+et+Passeport/16%20Chemin%20De%20La%20Haude,%2033160%20Saint-Aubin-de-M%C3%A9doc,%20France/44.913808/-0.724672 | grep -R ' my-1\" role=\"button\">' > recup.txt ";
	system(requete);
}

int		main(int argc, char **argv)
{
	int		min;
	int		max;

	min = ft_atoi(ft_strjoin(ft_substr(argv[1], 3, 2), ft_substr(argv[1], 0, 2)));
	max = ft_atoi(ft_strjoin(ft_substr(argv[2], 3, 2), ft_substr(argv[2], 0, 2)));
	while (1) 
	{
		recup_html();
		if (check_date(min, max) == 1)
			system("afplay ./alarm.mp3");
		else 
			ft_printf("Pas de resultat correspondant\n");
		sleep(30);
	}
	return (0);
}
