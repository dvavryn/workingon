/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:23:13 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/17 16:56:18 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_maperror(char *s, t_data **env, int status)
{
	write(2, "ERROR\n", 7);
	write(2, s, ft_strlen(s));
	free_env(env, status);
}

void	maperror(t_data **env, int e, int p, int c)
{
	if ((e == 1 && p == 1 && c > 0))
		return ;
	if (e < 1)
		print_maperror
("There should be one exit 'E' !\n", env, 2);
	else if (e > 1)
		print_maperror
("There should only be one exit 'E' !\n", env, 2);
	if (p < 1)
		print_maperror
("There should be one starting position 'P' !\n", env, 2);
	else if (p > 1)
		print_maperror
("There should only be one starting position 'P' !\n", env, 2);
	if (c == 0)
		print_maperror
("There should be at least one collectible 'C' !\n", env, 2);
}
