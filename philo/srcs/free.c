/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:41:32 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 17:05:53 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_free_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (data->philos[i])
		{
			pthread_mutex_destroy(&(data->philos[i])->own_fork);
			free(data->philos[i]);
			data->philos[i] = NULL;
		}
		i++;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}

void	ft_join_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
	ft_free_philos(data);
	if (data->philo_nb != 1)
		pthread_join(data->observer, NULL);
	if (data->all_meals_eaten)
	{
		free(data->all_meals_eaten);
		data->all_meals_eaten = NULL;
	}
}

void	ft_mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_unlock(&data->philos[i]->own_fork);
		pthread_mutex_destroy(&data->philos[i]->own_fork);
		i++;
	}
}
