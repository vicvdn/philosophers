/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:04:34 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/10 15:08:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_philo *philo)
{
	printf("%ld %d is thinking\n", ft_get_time(), philo->id);
}

void	ft_sleeping(t_data *data, t_philo *philo)
{
	printf("%ld %d is sleeping\n", ft_get_time(), philo->id);
	usleep(data->time_to_sleep); //not sure about this
}

void	ft_eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(philo->own_fork);
	printf("%ld %d has taken a fork\n", ft_get_time(), philo->id);
	if (data->philo_nb == 1)
	{
		usleep(data->time_to_die);
		pthread_mutex_lock(philo->death_lock);
		(data->is_dead) = 1;
		pthread_mutex_unlock(philo->death_lock);
		pthread_mutex_unlock(philo->own_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", ft_get_time(), philo->id);
	printf("%ld %d is eating\n", ft_get_time(), philo->id);
	philo->last_meal = ft_get_time();
	usleep(data->time_to_eat); //not sure about this
	philo->meals_eaten++;
}