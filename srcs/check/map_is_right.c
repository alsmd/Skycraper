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

#include <rush.h>

/*
	@brief	Check if the towers inside rush->map[4][4] is right according
			to the rule
*/
int	map_is_right(t_rush *rush)
{
	if (!check_colup(rush) || !check_coldown(rush))
		return (0);
	if (!check_rowleft(rush) || !check_rowright(rush))
		return (0);
	return (1);
}
