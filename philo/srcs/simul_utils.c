/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:18:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/10 09:41:40 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_philo_thread(t_data *data, t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, ft_routine, (void *) data) != 0)
	{
		printf("Error: pthread_creation failed\n");
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
			if (pthread_create(&data->observer, NULL, ft_observer, (void *)data) != 0)
			{
				printf("Error: pthread_creation failed\n");
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
	return (SUCCESS);
}

int ft_join_threads(t_data *data)
{
	t_philo	*philo;

	philo = data->philos;
	while (philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Error: pthread_join failed\n");
			return (ft_free_all(data), FAIL);
		}
		philo = philo->next;
	}
	if (pthread_join(data->observer, NULL) != 0)
	{
		printf("Error: pthread_join failed\n");
		return (ft_free_all(data), FAIL);
	}
	return (SUCCESS);
}