/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 16:06:15 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*ft_set_forks(int philo_nb)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * philo_nb);
	if (!forks)
		return (NULL);
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
			return (free(forks), NULL);
		}
		i++;
	}
	return (forks);
}

int	ft_init_rest_data(t_data *data)
{
	data->philos = NULL;
	data->start_time = 0;
	data->forks = ft_set_forks(data->philo_nb);
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