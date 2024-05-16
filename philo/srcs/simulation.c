/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:14:07 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/16 17:21:30 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->death_lock);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->death_lock);
	ft_print_message(philo, "died");
}

void	*ft_observer(void *arg)
{
	int	i;
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_nb)
		{
			pthread_mutex_lock(&data->read);
			if (data->philos[i]->last_meal == -1)
			{
				pthread_mutex_lock(&data->time);
				if (ft_get_time(data->philos[i]) > data->time_to_die)
				{
					pthread_mutex_unlock(&data->time);
					pthread_mutex_unlock(&data->read);
					ft_set_dead(data, data->philos[i]);
					return (NULL);
				}
				else
					pthread_mutex_unlock(&data->read);
				pthread_mutex_unlock(&data->time);
			}
			else
			{
				if (ft_get_time(data->philos[i]) - data->philos[i]->last_meal > data->time_to_die)
				{
					pthread_mutex_unlock(&data->read);
					ft_set_dead(data, data->philos[i]);
					return (NULL);
				}
				else
					pthread_mutex_unlock(&data->read);
			}
			i++;
		}
	}
}

void	ft_launch_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&data->philos[i]->thread, NULL, (void *) ft_routine, (void *)data->philos[i]);
		i++;
	}
	if (data->philo_nb != 1)
		pthread_create(&data->observer, NULL, (void *) ft_observer, (void *)data);
}

int	ft_launch_simulation(t_data *data)
{
	if (ft_init_philos(data) == FAIL)
		return (FAIL);
	ft_launch_threads(data);
	ft_join_and_free(data);
	return (SUCCESS);
}
