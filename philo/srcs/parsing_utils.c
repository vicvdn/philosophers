/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:10:20 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 15:14:07 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_set_forks(t_data *data)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!forks)
		return (FAIL);
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
			return (ft_free_all(data), FAIL);
		}
		i++;
	}
	return (forks);
}