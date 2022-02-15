/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:46:58 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 03:45:27 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

/*
	@brief	Check if the towers inside sky->map[4][4] is right according
			to the rule
*/
int	map_is_right(t_sky *sky)
{
	if (!check_colup(sky) || !check_coldown(sky))
		return (0);
	if (!check_rowleft(sky) || !check_rowright(sky))
		return (0);
	return (1);
}
