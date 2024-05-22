/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 17:58:33 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->own_fork);
	ft_print_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->own_fork);
	ft_usleep(philo, philo->time_to_die);
	ft_set_dead(philo->data, philo);
}

int	ft_set_time_to_think(int id, t_philo *philo)
{
	int	time;

	if (id % 2 != 0)
		usleep(100);
	time = philo->time_to_die - (philo->time_to_eat + philo->time_to_sleep);
	return (time);
}

void	ft_add_meals(t_philo *philo)
{
	if (philo->data->meals != -1)
	{
		pthread_mutex_lock(&philo->meals_lock);
		philo->meals++;
		pthread_mutex_unlock(&philo->meals_lock);
	}
}
