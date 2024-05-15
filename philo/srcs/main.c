/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:24:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 11:22:03 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_data 	data;

	if (ft_parse_args(ac, av, &data) == FAIL)
		return (FAIL);
	ft_init_rest_data(&data);
	ft_launch_simulation(&data);
	// if (ft_init_philos(&data) == FAIL)
	// 	return (FAIL);
	// ft_join_and_free(data.philos, data.philo_nb);
	// ft_free_all(&data);
	pthread_mutex_destroy(&data.print);
	return (0);
}