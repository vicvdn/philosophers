/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:10:20 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 14:22:09 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_set_forks(t_data *data)
{
	int				i;
	pthread_mutex_t	forks[data->philo_nb];

	// forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb + 1);
	// if (!forks)
	// 	return (NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&forks[i]);
				i--;
			}
			return (FAIL);
			// return (ft_free_philos(data), FAIL);
		}
		i++;
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	data->forks = forks;
	return (SUCCESS);
}