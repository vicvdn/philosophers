/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 16:53:18 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_forks(t_data *data, int philo_nb)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * philo_nb);
	if (!forks)
		return ;
	memset(forks, 0, sizeof(pthread_mutex_t) * philo_nb);
	i = 0;
	while (i < philo_nb)
	{
		memset(&forks[i], 0, sizeof(pthread_mutex_t));
		if (pthread_mutex_init(&(forks[i]), NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&(forks[i]));
				i--;
			}
			return (free(forks));
		}
		i++;
	}
	data->forks = forks;
}

int	ft_init_rest_data(t_data *data)
{
	data->philos = NULL;
	data->start_time = 0;
	ft_set_forks(data, data->philo_nb);
	if (data->forks == NULL)
		return (FAIL);
	data->is_dead = 0;
	memset(&data->death_lock, 0, sizeof(pthread_mutex_t));
	memset(&data->print, 0, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(&data->death_lock, NULL) == 0)
		return (free(data->forks), FAIL);
	if (pthread_mutex_init(&data->print, NULL) == 0)
		return (free(data->forks), FAIL);
	return (SUCCESS);
}
void	ft_fill_philo(t_philo *philo, t_data *data, int i)
{
	philo->id = i;
	philo->print = &data->print;
	philo->philo_nb = data->philo_nb;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->meals = data->meals;
	philo->own_fork = &data->forks[i];
	if (i == data->philo_nb - 1)
		philo->left_fork = &data->forks[0];
	else
		philo->left_fork = &data->forks[i + 1];
}
