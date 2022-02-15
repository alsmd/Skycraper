/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:46:56 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 18:50:00 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

int	main(int argc, char *argv[])
{
	t_sky	sky;
	if (argc < 6)
		return (0);
	
	if (!create_board(&sky, &argv[1]))
	{
		printf("Erro Creating Rule and Board!\n");
		return (0);
	}
	fill_square(&sky, 0, 0);
	print_board(&sky);
	return (0);
}
