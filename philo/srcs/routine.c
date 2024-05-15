/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:46 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 15:42:33 by vvaudain         ###   ########.fr       */
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
	// pthread_mutex_t	*mine;
	// pthread_mutex_t	*other;

	// mine = ;
	// other = philo->left_fork;
	/* 
	//if (philo->philo_nb == 1)
	// {
	// 	ft_usleep(philo, philo->time_to_die);
	// 	pthread_mutex_lock(philo->death_lock);
		// *(philo->is_dead) = 1;
	// 	pthread_mutex_unlock(philo->death_lock);
	// 	ft_print_message(philo, "died");
	// 	// pthread_mutex_unlock(philo->own_fork);
	// 	return ;
	// }
	*/

	// printf("voici les fourchettes : [%p] [%p]\n", &philo->forks[philo->mine], &philo->forks[philo->other]);
	
	
	pthread_mutex_lock(philo->print);
	printf("[%d]trying to lock [%d]\n", philo->id, philo->mine);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(&(philo->forks[philo->mine]));
	pthread_mutex_lock(philo->print);
	printf("[%d]locked\n", philo->id);
	pthread_mutex_unlock(philo->print);

	pthread_mutex_lock(philo->print);
	printf("[%d]trying to lock [%d]\n", philo->id, philo->other);
	pthread_mutex_unlock(philo->print);
	
	pthread_mutex_lock(&(philo->forks[philo->other]));
	
	pthread_mutex_lock(philo->print);
	printf("[%d]locked\n", philo->id);
	pthread_mutex_unlock(philo->print);
	// ft_print_message(philo, "has taken a fork");
	// pthread_mutex_lock(philo->print);
	// printf("coucou\n");
	// pthread_mutex_unlock(philo->print);
	// pthread_mutex_lock(philo->left_fork);
	// ft_print_message(philo, "has taken a fork");
	// // ft_print_message(philo, "has taken a fork");
	// // ft_print_message(philo, "is eating");
	// // philo->last_meal = ft_get_time();
	// // philo->meals_eaten++;
	ft_usleep(philo, philo->time_to_eat);
	
	// usleep(100);
	
	// pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->forks[philo->other]));
	
	pthread_mutex_lock(philo->print);
	printf("[%d]unlocked\n", philo->id);
	pthread_mutex_unlock(philo->print);

	pthread_mutex_unlock(&(philo->forks[philo->mine]));
	pthread_mutex_lock(philo->print);
	printf("[%d]unlocked\n", philo->id);
	pthread_mutex_unlock(philo->print);
	
	// pthread_mutex_unlock(&(philo->own_fork));
	usleep(100);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	int		j;

	philo = (t_philo *)arg;
	// j = 0;
	// ft_print_forks(philo);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		// if (*(philo->is_dead) == 1)
		// 	return (NULL);
		ft_eating(philo);
		// ft_thinking(philo);
		// ft_sleeping(philo);
		usleep(42);
		// j++;
	}
	printf("bye\n");
	// ft_eating(philo);
	// ft_thinking(philo);
	// ft_sleeping(philo);
	
	// pthread_mutex_lock(philo->print);
	// printf("Hello from thread %d\n", philo->id);
	// pthread_mutex_unlock(philo->print);
	return (NULL);
}
