/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:19:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/27 15:54:39 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <libc.h>

void		ft_modif2(t_user *user)
{
	user->age = 23;
	user->nom = "titi";
	user->prenom = "teuhteuh";
}

void		ft_modif(t_user *user)
{
	t_user	*envoi;
	
	envoi = user;
	printf("deuxieme = %p\n", envoi);
	free(envoi);

	ft_modif2(user);
}

int			main(void)
{
	t_user	*user;

	user = malloc(sizeof(t_user));

	printf("%p\n", user);
	ft_modif(user);
	printf("%p\n", user);
	free(user);

}
