/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:59:12 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/17 16:27:48 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*textures[5];
}	t_data;

void	errorcheck(t_data **env);
void	free_env(t_data	**env, int status);
void	print_maperror(char *s, t_data **env, int status);
void	maperror(t_data **env, int e, int p, int c);

#endif