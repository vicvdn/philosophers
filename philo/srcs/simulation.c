/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:50:44 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/10 15:32:43 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo			*philo;
	t_data			*data;

	data = (t_data *)arg;
	philo = data->philos;
	while (1)
	{
		if (data->is_dead == 1)
			break ;
		if (philo->meals_eaten == data->meals)
			break ;
		//make the philo eat when its 2 forks are available
		//make the philo think
		//make the philo sleep during data->time_to_sleep
	}
	return (NULL);
}

void	*ft_observer(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (data->is_dead == 1)
			break ;
	}
	exit(EXIT_FAILURE);//check if we need to say that a philo died
	return (NULL);
}

int	ft_launch_simulation(t_data *data)
{
	t_philo	*cur;

	cur = data->philos;
	while (cur)
	{
		if (ft_create_threads(data, cur) == FAIL)
			return (FAIL);
		cur = cur->next;
	}
	if (ft_create_threads(data, NULL) == FAIL)
		return (FAIL);
	if (ft_join_threads(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}