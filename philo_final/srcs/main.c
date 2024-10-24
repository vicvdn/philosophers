/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:24:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/21 15:15:33 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parse_args(ac, av, &data) == FAIL)
		return (FAIL);
	ft_init_rest_data(&data);
	ft_launch_simulation(&data);
	pthread_mutex_destroy(&data.print);
	pthread_mutex_destroy(&data.death_lock);
	return (0);
}
