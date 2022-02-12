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

#include <rush.h>

void	malloc_board(t_rush *rush)
{
	int	index;

	index = 0;
	rush->map = (char **) ft_calloc(rush->size, sizeof(char *));
	rush->rule = (char **) ft_calloc(4, sizeof(char *));
	rush->active_line = (char *) ft_calloc(rush->size, sizeof(char));
	rush->line_to_fill = (char *) ft_calloc(rush->size, sizeof(char));
	while (index < rush->size)
	{
		rush->map[index] = ft_calloc(rush->size, sizeof(char));
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

int	check_rule_size(t_rush *rush, char *rule[])
{
	int	index;
	int	line_size;

	index = 0;
	while (rule[index])
	{
		line_size = ft_strlen(rule[index]);
		if (!has_just_number(rule[index]))
			return (1);
		if (line_size != rush->size)
			return (1);
		if (index == 4)
			return (1);
		index++;
	}
	if (index < 3)
		return (1);
	return (0);
}

void	create_rule(t_rush *rush, char *rule[])
{
	int	index;

	index = 0;
	while (rule[index])
	{
		rush->rule[index] = rule[index];
		index++;
	}
}
int	create_board(t_rush *rush, char *argv[])
{
	rush->size = ft_atoi(argv[0]);
	if (rush->size < 4 || rush->size > 9)
		return (0);
	malloc_board(rush);
	if (check_rule_size(rush, &argv[1]))
		return (0);
	create_rule(rush, &argv[1]);
	return (1);
}
