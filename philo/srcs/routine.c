/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:46 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 17:58:03 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleeping(t_philo *philo)
{
	ft_print_message(philo, "is sleeping");
	ft_usleep(philo, philo->time_to_sleep);
	return ;
}

void	ft_last_philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->philos[philo->other]->own_fork);
	ft_print_message(philo, "has taken a fork other");
	pthread_mutex_lock(&philo->own_fork);
	ft_print_message(philo, "has taken a fork mine");
	pthread_mutex_lock(&philo->data->read);
	philo->last_meal = ft_get_time_from_start(philo);
	pthread_mutex_unlock(&philo->data->read);
	ft_print_message(philo, "is eating");
	ft_usleep(philo, philo->time_to_eat);
	pthread_mutex_unlock(&philo->own_fork);
	pthread_mutex_unlock(&philo->data->philos[philo->other]->own_fork);
}

void	ft_eating(t_philo *philo)
{
	if (philo->philo_nb == 1)
	{
		ft_handle_single_philo(philo);
		return ;
	}
	if (philo->id == philo->philo_nb - 1)
		ft_last_philo_eating(philo);
	else
	{
		pthread_mutex_lock(&philo->own_fork);
		ft_print_message(philo, "has taken a fork mine");
		pthread_mutex_lock(&philo->data->philos[philo->other]->own_fork);
		ft_print_message(philo, "has taken a fork other");
		pthread_mutex_lock(&philo->data->read);
		philo->last_meal = ft_get_time_from_start(philo);
		pthread_mutex_unlock(&philo->data->read);
		ft_print_message(philo, "is eating");
		ft_usleep(philo, philo->time_to_eat);
		pthread_mutex_unlock(&philo->data->philos[philo->other]->own_fork);
		pthread_mutex_unlock(&philo->own_fork);
	}
}

int	ft_stop(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (YES);
	}
	pthread_mutex_unlock(philo->death_lock);
	return (NO);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		time_to_think;

	philo = (t_philo *)arg;
	data = philo->data;
	time_to_think = ft_set_time_to_think(philo->id, philo);
	while (ft_stop(philo) == NO)
	{
		ft_eating(philo);
		ft_add_meals(philo);
		if (ft_stop(philo) == YES)
			return (NULL);
		ft_sleeping(philo);
		if (ft_stop(philo) == YES)
			return (NULL);
		ft_print_message(philo, "is thinking");
		if (ft_stop(philo) == YES)
			return (NULL);
		ft_usleep(philo, time_to_think / 2);
	}
	return (NULL);
}
