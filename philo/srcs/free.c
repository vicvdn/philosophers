/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:41:32 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/16 16:01:19 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_join_and_free(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
	if (data->philo_nb != 1)
		pthread_join(data->observer, NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		if (data->philos[i])
			free(data->philos[i]);
		i++;
	}
	if (data->philos)
		free(data->philos);
}

void	ft_mutex_destroy(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_unlock(&data->philos[i]->own_fork);
		pthread_mutex_destroy(&data->philos[i]->own_fork);
		i++;
	}
}
