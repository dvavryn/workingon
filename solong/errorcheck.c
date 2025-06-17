/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:10:53 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/17 17:00:52 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	errorcheck_shape(t_data **env);
static void	errorcheck_symbols(t_data **env);
static void	errorcheck_walls(t_data **env);
static void	errorcheck_occurance(t_data **env);

void	errorcheck(t_data **env)
{
	if (!(*env)->map)
		free_env(env, 2);
	errorcheck_shape(env);
	errorcheck_symbols(env);
	errorcheck_walls(env);
	errorcheck_occurance(env);
}

static void	errorcheck_shape(t_data **env)
{
	size_t	i;

	i = 0;
	while ((*env)->map[i])
	{
		if (ft_strlen((*env)->map[0]) != ft_strlen((*env)->map[i]))
			print_maperror("The map is not rectangular!\n", env, 2);
		i++;
	}
}

static void	errorcheck_symbols(t_data **env)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while ((*env)->map[i])
	{
		j = 0;
		while ((*env)->map[i][j])
		{
			c = (*env)->map[i][j];
			if (!(c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'P'))
				print_maperror("Invalid map input!\nThe map should only contain \
'0', '1', 'E', 'C' and 'P' !\n", env, 2);
			j++;
		}
		i++;
	}
}

static void	errorcheck_walls(t_data **env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*env)->map[i])
	{
		j = 0;
		while ((*env)->map[i][j])
		{
			if ((i == 0 || !(*env)->map[i + 1] || j == 0
					|| !(*env)->map[i][j + 1]) && (*env)->map[i][j] != '1')
				print_maperror("The map is not surrounded by Walls '1' !\n",
						env, 2);
			j++;
		}
		i++;
	}
}

// static void	errorcheck_occurance(t_data **env)
// {
// 	size_t	count[3];
// 	size_t	i;
// 	size_t	j;
	
// 	i = 0;
// 	count[0] = 0;
// 	count[1] = 0;
// 	count[2] = 0;
// 	while ((*env)->map[i])
// 	{
// 		j = 0;
// 		while ((*env)->map[i][j])
// 		{
// 			count[0] += ((*env)->map[i][j] == 'E') * 1;
// 			count[1] += ((*env)->map[i][j] == 'P') * 1;
// 			count[2] += ((*env)->map[i][j] == 'C') * 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	maperror(env, count[0], count[1], count[2]);
// 	validate_map(env, count[0], count[1], count[2]);
// }

char	**cpy_map(t_data **env)
{
	size_t	i;
	char	**out;

	i = 0;
	while ((*env)->map[i])
		i++;
	out = malloc((i + 1) * sizeof(char *));
	if (!out)
		free_env(env, 3);
	i = 0;
	while ((*env)->map[i])
	{
		out[i] = ft_strdup((*env)->map[i]);
		if (!out[i])
		{
			free_split(out);
			free_env(env, 3);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}


static void	errorcheck_occurance(t_data **env)
{
	char	**buf;
	ssize_t	count[3];

	buf = cpy_map(env);
}
