/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:50:44 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 15:17:39 by vvaudain         ###   ########.fr       */
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
		if (philo->meals_eaten == data->meals)
			break ;
		
		//make the philo eat when its 2 forks are available
		//make the philo think
		//make the philo sleep during data->time_to_sleep
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
	if (ft_join_threads(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}