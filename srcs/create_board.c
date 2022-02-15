/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:06:24 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 16:02:22 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

void	malloc_board(t_sky *sky)
{
	int	index;

	index = 0;
	sky->map = (char **) ft_calloc(sky->size, sizeof(char *));
	sky->rule = (char **) ft_calloc(4, sizeof(char *));
	sky->active_line = (char *) ft_calloc(sky->size, sizeof(char));
	sky->line_to_fill = (char *) ft_calloc(sky->size, sizeof(char));
	while (index < sky->size)
	{
		sky->map[index] = ft_calloc(sky->size, sizeof(char));
		index++;
	}
}

int	has_just_number(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

int	check_rule_size(t_sky *sky, char *rule[])
{
	int	index;
	int	line_size;

	index = 0;
	while (rule[index])
	{
		line_size = ft_strlen(rule[index]);
		if (!has_just_number(rule[index]))
			return (1);
		if (line_size != sky->size)
			return (1);
		if (index == 4)
			return (1);
		index++;
	}
	if (index < 3)
		return (1);
	return (0);
}

void	create_rule(t_sky *sky, char *rule[])
{
	int	index;

	index = 0;
	while (rule[index])
	{
		sky->rule[index] = rule[index];
		index++;
	}
}
int	create_board(t_sky *sky, char *argv[])
{
	sky->size = ft_atoi(argv[0]);
	if (sky->size < 4 || sky->size > 9)
		return (0);
	malloc_board(sky);
	if (check_rule_size(sky, &argv[1]))
		return (0);
	create_rule(sky, &argv[1]);
	return (1);
}
