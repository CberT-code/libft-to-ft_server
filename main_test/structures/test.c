/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:19:31 by cbertola          #+#    #+#             */
/*   Updated: 2019/12/07 14:39:06 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void		ft_modif2(t_user *user)
{
	user->age = 23;
	user->nom = "titi";
	user->prenom = "teuhteuh";
}

void		ft_modif(t_user *user)
{
	user->age = 22;
	user->nom = "tata";
	user->prenom = "totou";
	ft_modif2(user);
}

int			main(void)
{
	t_user	user;

	user.age = 21;
	user.nom = "toto";
	user.prenom = "titi";

	printf("user.age = %d\n", user.age);
	printf("user.nom = %s\n", user.nom);
	printf("user.prenom = %s\n", user.prenom);

	ft_modif(&user);
	printf("user.age = %d\n", user.age);
	printf("user.nom = %s\n", user.nom);
	printf("user.prenom = %s\n", user.prenom);

}
