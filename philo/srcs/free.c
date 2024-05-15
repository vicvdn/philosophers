/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:41:32 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 12:14:27 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_join_and_free(t_philo **philos, int philo_nb)
{
	int i;

	i = 0;
	while (i < philo_nb)
	{
		if (philos[i] && philos[i]->thread)
			pthread_join(philos[i]->thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo_nb)
	{
		if (philos[i])
			free(philos[i]);
		i++;
	}
	if (philos)
		free(philos);
}

void ft_free_all(t_data *data)
{
	if (data->forks)
		free(data->forks);
}