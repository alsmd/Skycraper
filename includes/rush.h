/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:03 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 13:11:57 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# define LOWER 0
# define HIGHER 1
# include <stdio.h>

typedef struct s_rush
{
	char	rule[4][4];
	char	map[4][4];
	int		size;
	int		higher_tower;
	int		towers_in_view;
	int		missing_towers;
	char	active_line[4];
	int		index;
}	t_rush;

void	reset(t_rush *rush);
int		fill_square(t_rush *rush, int line, int col);

//Checks

int		map_is_right(t_rush *rush);
int		wrong_sight(t_rush *rush, int has_to_see);
int		check_coldown(t_rush *rush);
int		check_colup(t_rush *rush);
int		check_rowleft(t_rush *rush);
int		check_rowright(t_rush *rush);

//Utils

int		is_in(char *array, int c, int size);
void	set_options(char option[4]);
int		ft_atoi(const char *nptr);

#endif