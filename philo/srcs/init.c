/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/17 16:53:15 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_fill_philo(t_philo *philo, t_data *data, int i)
{
	philo->id = i;
	philo->print = &data->print;
	philo->philo_nb = data->philo_nb;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->meals = data->meals;
	philo->last_meal = -1;
	philo->start_time = data->start_time;
	if (i == data->philo_nb - 1)
		philo->other = 0;
	else
		philo->other = i + 1;
	philo->death_lock = &data->death_lock;
	pthread_mutex_init(&philo->own_fork, NULL);
	philo->data = data;
}

int ft_init_philos(t_data *data)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * data->philo_nb);
	if (!philos)
		return (FAIL);
	data->start_time = ft_get_start_time();
	while (i < data->philo_nb)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (FAIL);
		ft_fill_philo(philos[i], data, i);
		i++;
	}
	data->philos = philos;
	return (SUCCESS);
}

int	ft_init_rest_data(t_data *data)
{
	data->philos = NULL;
	data->start_time = 0;
	data->is_dead = 0;
	data->all_meals_eaten = NULL;
	if (data->meals != -1)
	{
		data->all_meals_eaten = malloc(sizeof(int) * data->philo_nb);
		if (!data->all_meals_eaten)
			return (FAIL);
		memset(data->all_meals_eaten, 0, sizeof(int) * data->philo_nb);
	}
	memset(&data->death_lock, 0, sizeof(pthread_mutex_t));
	memset(&data->print, 0, sizeof(pthread_mutex_t));
	memset(&data->read, 0, sizeof(pthread_mutex_t));
	// memset(&data->time, 0, sizeof(pthread_t));
	memset(&data->add_meals, 0, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(&data->death_lock, NULL) == 0)
		return (FAIL);
	if (pthread_mutex_init(&data->print, NULL) == 0)
		return (FAIL);
	if (pthread_mutex_init(&data->read, NULL) == 0)
		return (FAIL);
	// if (pthread_mutex_init(&data->time, NULL) == 0)
	// 	return (FAIL);
	if (pthread_mutex_init(&data->add_meals, NULL) == 0)
		return (FAIL);
	return (SUCCESS);
}
