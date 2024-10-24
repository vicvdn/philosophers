/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:09:09 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 17:10:36 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->death_lock);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->death_lock);
	ft_print_dead_message(philo, "died");
}

void	ft_stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->death_lock);
}
