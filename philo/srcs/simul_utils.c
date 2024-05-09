/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:18:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 14:19:09 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_philo_thread(t_data *data, t_philo *philo)
{
	if (pthread_create(philo->thread, NULL, ft_routine, (void *) data) != 0)
	{
		printf("Error: pthread_create\n");
		return (ft_free_all(data), FAIL);
	}
	return (SUCCESS);
}

int	ft_create_threads(t_data *data)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = data->philos;
	while (i < data->philo_nb + 1)
	{
		if (i == data->philo_nb)
		{
			if (pthread_create(data->observer, NULL, ft_observer, (void *)data) != 0)
			{
				printf("Error: pthread_create\n");
				return (ft_free_all(data), FAIL);
			}
			
		}
		else
		{
			if (ft_philo_thread(data, philo) == FAIL)
				return (FAIL);
			philo = philo->next;
		}
		i++;
	}
}