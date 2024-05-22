/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:14:07 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/21 15:17:47 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_launch_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&data->philos[i]->thread, NULL,
			(void *) ft_routine, (void *)data->philos[i]);
		i++;
	}
	if (data->philo_nb != 1)
		pthread_create(&data->observer, NULL,
			(void *) ft_observer, (void *)data);
}

int	ft_launch_simulation(t_data *data)
{
	if (ft_init_philos(data) == FAIL)
		return (FAIL);
	ft_launch_threads(data);
	ft_join_and_free(data);
	return (SUCCESS);
}
