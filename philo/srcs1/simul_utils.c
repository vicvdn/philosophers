/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:18:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 14:22:17 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->print_lock);
	printf("%ld %d %s\n", ft_get_time(), philo->id, message);
	pthread_mutex_unlock(philo->print_lock);
}

bool ft_death_check(t_philo *philo)
{
	if (philo->is_dead == 1)
		return (true);
	else
		return (false);
}

int	ft_create_threads(t_data *data, t_philo *cur)
{
	pthread_t	observer;

	if (!cur)
	{
		if (pthread_create(&observer, NULL, ft_observer, (void *)data) != 0)
			return (FAIL);
			// return (ft_free_philos(data), FAIL);
		data->observer = observer;
	}
	else
	{
		if (pthread_create(&cur->thread, NULL, ft_routine, (void *)data) != 0)
			return (FAIL);
	}
	return (SUCCESS);
}

// int ft_join_and_free_threads(t_data *data)
// {
// 	t_philo	*cur;
// 	t_philo	*tmp;

// 	cur = data->philos;
// 	while (cur)
// 	{
// 		tmp = cur->next;
// 		if (pthread_join(cur->thread, NULL) != 0)
// 		{
// 			printf("Error: pthread_join failed\n");
// 			return (ft_free_philos(data), FAIL);
// 		}
// 		free(cur);
// 		cur = tmp;
// 	}
// 	// if (pthread_join(data->observer, NULL) != 0)
// 	// {
// 	// 	printf("Error: pthread_join failed\n");
// 	// 	return (ft_free_philos(data), FAIL);
// 	// }
// 	ft_free_rest(data);
// 	return (SUCCESS);
// }