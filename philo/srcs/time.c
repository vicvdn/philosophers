/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:19:43 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 15:47:34 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_get_time(void)
{
	struct timeval	time;
	size_t			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

size_t	ft_get_time_from_start(t_philo *philo)
{
	struct timeval	time;
	size_t			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res - philo->start_time);
}

size_t	ft_get_start_time(void)
{
	struct timeval	time;
	size_t			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

void	ft_print_dead_message(t_philo *philo, char *message)
{
	long	time;

	time = ft_get_time_from_start(philo);
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", time, philo->id + 1, message);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_usleep(t_philo *philo, size_t time)
{
	size_t	start;

	start = ft_get_time_from_start(philo);
	if (time <= 0)
		return ;
	while (ft_get_time_from_start(philo) - start < time)
	{
		pthread_mutex_lock(&philo->data->death_lock);
		if (philo->data->is_dead == 1)
		{
			pthread_mutex_unlock(&philo->data->death_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->data->death_lock);
		usleep(1000);
	}
}

// void	ft_usleep(t_philo *philo, size_t time)
// {
// 	size_t	start;

// 	start = ft_get_time_from_start(philo);
// 	while (ft_get_time_from_start(philo) - start < time)
// 		usleep(100);
// 	return ;
// }