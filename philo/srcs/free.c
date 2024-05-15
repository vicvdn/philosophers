/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:41:32 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 17:05:52 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void ft_join_and_free(t_philo **philos, int philo_nb)
// {
// 	int i;

// 	i = 0;
// 	while (i < philo_nb)
// 	{
// 		// if (!philos[i])
// 		// {
// 		// 	printf("philo %d is NULL\n", i);
// 		// 	break;
// 		// }
// 		// if (!philos[i]->thread)
// 		// {
// 		// 	printf("thread %d is NULL\n", i);
// 		// 	break;
// 		// }
// 		if (philos[i] && philos[i]->thread)
// 			pthread_join(philos[i]->thread, NULL);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < philo_nb)
// 	{
// 		if (philos[i])
// 			free(philos[i]);
// 		i++;
// 	}
// 	if (philos)
// 		free(philos);
// }

void ft_join_and_free(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		// if (data->philos[i] == NULL)
		// {
		// 	printf("philo %d is NULL\n", i);
		// 	break;
		// }
		// else
		// 	printf("philo %d is not NULL\n", i);
		// printf("philos[%d]->thread = %lu\n", i, data->philos[i]->thread);
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
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

void ft_free_all(t_data *data)
{
	if (data->forks)
		free(data->forks);
}