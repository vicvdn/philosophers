/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:46 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 12:15:42 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_philo *philo)
{
	ft_print_message(philo, "is thinking");
	ft_usleep(philo, 100);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_message(philo, "is sleeping");
	ft_usleep(philo, philo->time_to_sleep);
}

void	ft_eating(t_philo *philo)
{
	// pthread_mutex_lock(philo->own_fork);
	// ft_print_message(philo, "has taken a fork");
	if (philo->philo_nb == 1)
	{
		ft_usleep(philo, philo->time_to_die);
		pthread_mutex_lock(philo->death_lock);
		*(philo->is_dead) = 1;
		pthread_mutex_unlock(philo->death_lock);
		ft_print_message(philo, "died");
		pthread_mutex_unlock(philo->own_fork);
		return ;
	}
	// pthread_mutex_lock(philo->left_fork);
	// ft_print_message(philo, "has taken a fork");
	// ft_print_message(philo, "is eating");
	// philo->last_meal = ft_get_time();
	// philo->meals_eaten++;
	// ft_usleep(philo, philo->time_to_eat);
	// pthread_mutex_unlock(philo->own_fork);
	// pthread_mutex_unlock(philo->left_fork);
}

void	ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep(500);
	ft_eating(philo);
	ft_thinking(philo);
	ft_sleeping(philo);
	// pthread_mutex_lock(philo->print);
	// printf("Hello from thread %d\n", philo->id);
	// pthread_mutex_unlock(philo->print);
}