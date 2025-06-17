/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:57:15 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/17 16:56:55 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// typedef struct	s_data
// {
// 	char	**map;
// 	void	*mlx;
// 	void	*win;
// 	void	*textures[5];
// }	t_data;

// Textures

void	init_textures(t_data **env)
{
	return ;
}

// Map

char *read_map(char *path)
{
	ssize_t	b;
	int		fd;
	char	s[10];
	char	*tmp;
	char	*out;

	fd = open(path, O_RDONLY);
	out = ft_strdup("");
	if (fd < 0 || !out)
		return (NULL);
	b = 1;
	ft_bzero(s, sizeof(s));
	while (b > 0)
	{
		b = read(fd, s, sizeof(s) - 1);
		if (b == -1)
			return (NULL);
		tmp = out;
		out = ft_strjoin(out, s);
		free(tmp);
		if (!out || !ft_strlen(out))
			return (NULL);
		ft_bzero(s, sizeof(s));
	}
	return (out);
}

void	init_map(t_data **env, char *map_path)
{
	char	*oneline;

	if (ft_strcmp(&map_path[sizeof(map_path) - 5], ".ber"))
		exit(1);
	oneline = read_map(map_path);
	if (!oneline)
	{
		(*env)->map = NULL;
		return ;
	}
	(*env)->map = ft_split(oneline, '\n');
	free(oneline);
	if (!(*env)->map)
		(*env)->map = NULL;
	errorcheck(env);
}

void	init_env(t_data **env, char *map_path)
{
	*env = malloc(sizeof(t_data));
	if (!(*env))
		free_env(env, 1);

	init_map(env, map_path);
	if (!(*env)->map)
		free_env(env, 1);

	// (*env)->mlx = mlx_init();
	// if (!(*env)->mlx)
	// 	free_env(env, 1);

	// (*env)->win = mlx_new_window((*env)->mlx, 400, 400, "Hi");
	// if (!(*env)->win)
	// 	free_env(env, 1);

	// init_textures(env);
	// if (!check_textures(env))
		// free_env(env, 1);
}

int	main(int argc, char **argv)
{
	t_data	*env;

	init_env(&env, "map.ber");
	for (int i = 0; env->map[i]; i++)
	{
		ft_printf("%s\n", env->map[i]);
	}
	free_env(&env, 0);
}
