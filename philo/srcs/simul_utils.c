/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:18:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/10 15:31:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_create_threads(t_data *data, t_philo *cur)
{
	pthread_t	observer;
	pthread_t	thread;

	if (!cur)
	{
		if (pthread_create(&observer, NULL, ft_observer, (void *)data) != 0)
			return (ft_free_all(data), FAIL);
		data->observer = observer;
	}
	else
	{
		if (pthread_create(&thread, NULL, ft_routine, (void *)data) != 0)
			return (FAIL);
		cur->thread = thread;
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