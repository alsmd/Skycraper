/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:03 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 16:02:21 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# define LOWER 1
# define HIGHER -1
# include <stdio.h>
# include <stdlib.h>
typedef struct s_rush
{
	char	**rule;
	char	**map;
	int		size;
	int		higher_tower;
	int		towers_in_view;
	int		missing_towers;
	char	*active_line;
	char	*line_to_fill;
	int		index;
}	t_rush;

void	reset(t_rush *rush);
int		fill_square(t_rush *rush, int line, int col);

//Create board
int	create_board(t_rush *rush, char *argv[]);
int	get_lower_tower(t_rush *rush, char *active_line);

//Checks

int		map_is_right(t_rush *rush);
int		wrong_sight(t_rush *rush, int has_to_see);
int		check_coldown(t_rush *rush);
int		check_colup(t_rush *rush);
int		check_rowleft(t_rush *rush);
int		check_rowright(t_rush *rush);

//Utils

int		is_in(char *array, int c, int size);
void	set_options(t_rush *rush, char *option);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);
void	print_board(t_rush *rush);

#endif