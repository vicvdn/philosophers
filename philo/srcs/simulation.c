/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:50:44 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 14:19:01 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	data = (t_data *)arg;
	philo = data->philos;
	while (1)
	{
		if (data->death_flag == 1)
			break ;
	}
}

void	*ft_observer(void *arg)
{
	t_data	*data;

	data = (t_data *)data;
	while (1)
	{
		if (data->death_flag == 1)
			break ;
	}
}

int	ft_launch_simulation(t_data *data)
{
	if (ft_create_threads(data) == FAIL)
		return (FAIL);
	ft_start_simulation(data);
	return (SUCCESS);
}