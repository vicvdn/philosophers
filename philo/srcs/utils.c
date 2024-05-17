/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:30:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/17 15:15:06 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

size_t ft_get_time(void)
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

void	ft_print_message(t_philo *philo, char *message)
{
	long	time;

	time = ft_get_time_from_start(philo);
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->death_lock);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->death_lock);
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	pthread_mutex_unlock(&philo->data->death_lock);
	printf("%ld %d %s\n", time, philo->id + 1, message);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_usleep(t_philo *philo, size_t time)
{
	size_t	start;

	start = ft_get_time_from_start(philo);
	while (ft_get_time_from_start(philo) - start < time)
	{
		pthread_mutex_lock(&philo->data->death_lock);
		if (philo->data->is_dead == 1)
		{
			pthread_mutex_unlock(&philo->data->death_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->data->death_lock);
		// printf("coucou");
		usleep(5000);
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