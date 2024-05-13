/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:50:44 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/13 16:36:44 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->is_dead == 1)
			break ;
		if (philo->meals_eaten == philo->meals)
			break ;
		usleep(500);
		//make the philo eat when its 2 forks are available
		ft_eating(philo);
		//make the philo think
		ft_thinking(philo);
		//make the philo sleep during data->time_to_sleep
		ft_sleeping(philo);
	}
	return (NULL);
}

void	*ft_observer(void *arg)
{
	t_data	*data;
	t_philo	*cur;

	data = (t_data *)arg;
	cur = data->philos;
	while (1)
	{
		if (data->is_dead == 1)
			break ;
		if (data->meals != -1)
		{
			while (data->philos->meals_eaten < data->meals)
			{
				//check if all philos have eaten the required number of meals
				//if yes, set data->is_dead to 1
			}
			//check if all philos have eaten the required number of meals
			//if yes, set data->is_dead to 1
		}
	}
	//check if we need to say that a philo died
	return (NULL);
}

int	ft_launch_simulation(t_data *data)
{
	t_philo	*cur;

	cur = data->philos;
	data->start_time = ft_get_time();
	ft_print_data(data);
	// while (cur)
	// {
	// 	ft_print_philo_2(cur);
	// 	cur = cur->next;
	// }
	// cur = data->philos;
	while (cur)
	{
		if (ft_create_threads(data, cur) == FAIL)
			return (FAIL);
		cur = cur->next;
	}
	// if (ft_create_threads(data, NULL) == FAIL)
	// 	return (FAIL);
	if (ft_join_threads(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}