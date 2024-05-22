/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 10:41:56 by vvaudain         ###   ########.fr       */
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

void	ft_set_time_to_think(int id, t_data *data)
{
	if (id % 2 != 0)
		usleep(100);
	pthread_mutex_lock(&data->read);
	data->time_to_think = data->time_to_die
		- (data->time_to_eat + data->time_to_sleep);
	pthread_mutex_unlock(&data->read);
}
