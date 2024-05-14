/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:31 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 14:19:56 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	ft_free_philos(t_data *data)
// {
// 	t_philo	*cur;
// 	t_philo	*tmp;

// 	cur = data->philos;
// 	while (cur)
// 	{
// 		if (cur)
// 		{
// 			tmp = cur->next;
// 			free(cur);
// 		}
// 		cur = tmp;
// 	}
// }

void	ft_free_rest(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->forks[i]);
		// if (data->forks)
		// 	free(data->forks);
		i++;
	}
	if (data)
		free(data);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		printf("destroying fork %d\n", i);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->print);
}