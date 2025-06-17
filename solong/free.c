/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:17:39 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/17 15:17:49 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_env(t_data	**env, int status)
{
	size_t	i;

	if (!*env)
		exit(1);
	if ((*env)->map)
		free_split((*env)->map);
	i = 0;
	while (i < 5)
	{
		if ((*env)->textures[i])
			mlx_destroy_image((*env)->mlx, (*env)->textures[i]);
		i++;
	}
	if ((*env)->win)
		mlx_destroy_window((*env)->mlx, (*env)->win);
	if ((*env)->mlx)
	{
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	free(*env);
	exit(status);
}
