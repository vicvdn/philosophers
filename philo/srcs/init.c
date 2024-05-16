/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/16 13:47:25 by vvaudain         ###   ########.fr       */
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
	i = 0;
	while (i < data->philo_nb)
	{
		// printf("COUCOU philos[%d]->own_fork = %p\n", i, philos[i]->own_fork);
		// printf("COUCOU philos[%d]->left_fork = %p\n", i, philos[i]->left_fork);

		// philos[i]->thread = malloc(sizeof(pthread_t));
		// if (!philos[i]->thread)
		// 	return (ft_join_and_free(philos, i), FAIL);
		// ft_print_forks(philos[i]);
		pthread_create(&philos[i]->thread, NULL, (void *) ft_routine, (void *)philos[i]); //to protect
		i++;
	}
	return (SUCCESS);
}

pthread_mutex_t	*ft_set_forks(t_data *data, int philo_nb)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * philo_nb);
	if (!forks)
		return (NULL);
	// memset(forks, 0, sizeof(pthread_mutex_t) * philo_nb);
	i = 0;
	while (i < philo_nb)
	{
		// memset(&forks[i], 0, sizeof(pthread_mutex_t));
		if (pthread_mutex_init(&(forks[i]), NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&(forks[i]));
				i--;
			}
			return (free(forks), NULL);
		}
		i++;
		// pthread_mutex_lock(&forks[i]);
		// printf("forks[%d] = %p\n", i, &forks[i]);
		// pthread_mutex_unlock(&forks[i]);
	}
	// data->forks = forks;
	return (forks);
}

int	ft_init_rest_data(t_data *data)
{
	data->philos = NULL;
	data->start_time = 0;
	// data->forks = ft_set_forks(data, data->philo_nb);
	// if (data->forks == NULL)
	// 	return (FAIL);
	data->is_dead = 0;
	memset(&data->death_lock, 0, sizeof(pthread_mutex_t));
	memset(&data->print, 0, sizeof(pthread_mutex_t));
	// memset(&data->read, 0, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(&data->death_lock, NULL) == 0)
		return (FAIL);
	if (pthread_mutex_init(&data->print, NULL) == 0)
		return (FAIL);
	// if (pthread_mutex_init(&data->read, NULL) == 0)
	// 	return (free(data->forks), FAIL);
	return (SUCCESS);
}
