/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:24:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/16 13:09:25 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	
	// pthread_mutex_t	mine;
	// pthread_mutex_t	*mine;
	t_data 	data;

	if (ft_parse_args(ac, av, &data) == FAIL)
		return (FAIL);
	
	ft_init_rest_data(&data);
	ft_launch_simulation(&data);

	// pthread_mutex_lock(&mine);
	// pthread_mutex_t	*other;
	
	// mine = data.philos[0]->own_fork;
	// other = data.philos[0]->left_fork;

	// printf(" data.philos[0]->own_fork = %p\n", data.philos[0]->own_fork);
	// pthread_mutex_lock(data.philos[0]->own_fork);
	// // printf("COUCOU\n");
	// ft_print_message(data.philos[0], "has taken a fork");
	// pthread_mutex_unlock(data.philos[0]->own_fork);
	// printf("has been unlocked\n");

	// // if (ft_init_philos(&data) == FAIL)
	// // 	return (FAIL);
	// // ft_join_and_free(data.philos, data.philo_nb);
	// // ft_free_all(&data);
	pthread_mutex_destroy(&data.print);
	pthread_mutex_destroy(&data.death_lock);
	return (0);
}