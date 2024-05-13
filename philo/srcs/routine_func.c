/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:04:34 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/13 15:27:53 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(size_t time)
{
	size_t	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	printf("%ld %d is thinking\n", ft_get_time(), philo->id);
	pthread_mutex_unlock(philo->print_lock);
}

void	ft_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	printf("%ld %d is sleeping\n", ft_get_time(), philo->id);
	pthread_mutex_unlock(philo->print_lock);
	ft_usleep(*philo->time_to_sleep); //not sure about this
}

void	ft_eating(t_philo *philo)
{
	printf("philo->own_fork: %p\n", &philo->own_fork);
	pthread_mutex_lock(&philo->own_fork);
	pthread_mutex_lock(philo->print_lock);
	printf("%ld %d has taken a fork\n", ft_get_time(), philo->id);
	pthread_mutex_unlock(philo->print_lock);
	if (philo->philo_nb == 1)
	{
		ft_usleep(*philo->time_to_die);
		pthread_mutex_lock(philo->death_lock);
		(philo->is_dead) = 1;
		pthread_mutex_unlock(philo->death_lock);
		pthread_mutex_unlock(&philo->own_fork);
		return ;
	}
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(philo->print_lock);
	printf("%ld %d has taken a fork\n", ft_get_time(), philo->id);
	printf("%ld %d is eating\n", ft_get_time(), philo->id);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_unlock(&philo->own_fork);
	pthread_mutex_unlock(&philo->left_fork);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	ft_usleep(*philo->time_to_eat); //not sure about this
}
