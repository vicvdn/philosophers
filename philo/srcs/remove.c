/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:34:39 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/13 16:34:52 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_philos(t_data *data)
{
	t_philo	*cur;

	cur = data->philos;
	if (!cur)
	{
		printf("No philosophers\n");
		return ;
	}
	printf("-----Philo\t Meals_eaten\t Prev\t\t Cur\t\t Next\t\t lfork\t\t print\t\t-----\n");
	while (cur)
	{
		printf("----- %d\t\t\t", cur->id);
		printf(" %d\t", cur->meals_eaten);
		printf(" %p\t", cur->prev);
		if (cur->prev == NULL)
			printf("\t");
		printf(" %p\t", cur);
		printf(" %p\t", cur->next);
		printf(" %p\t\n", &cur->left_fork);
		// printf("----- %d\t\t\t %d\t\t\t %d\t\t %d\t\t -----\n", cur->id, cur->meals_eaten, cur->prev->id, cur->next->id);
		cur = cur->next;
	}
}

void	ft_print_data(t_data *data)
{
	printf("philo_nb = %d\n", data->philo_nb);
	printf("start_time = %ld\n", data->start_time);
	printf("time_to_die = %ld\n", data->time_to_die);
	printf("time_to_eat = %ld\n", data->time_to_eat);
	printf("time_to_sleep = %ld\n", data->time_to_sleep);
	printf("meals = %d\n", data->meals);
	printf("is_dead = %d\n", data->is_dead);
	printf("forks = %p\n", data->forks);
	printf("-------------------------------------------\n");
}

void	ft_print_philo_2(t_philo *philo)
{
	printf("id = %d\n", philo->id);
	printf("meals_eaten = %d\n", philo->meals_eaten);
	printf("last_meal = %ld\n", philo->last_meal);
	printf("is_dead = %d\n", philo->is_dead);
	printf("meals = %d\n", philo->meals);
	printf("start_time = %ld\n", philo->start_time);
	printf("time_to_die = %ld\n", *philo->time_to_die);
	printf("time_to_eat = %ld\n", *philo->time_to_eat);
	printf("time_to_sleep = %ld\n", *philo->time_to_sleep);
	printf("philo_nb = %d\n", philo->philo_nb);
	printf("own_fork = %p\n", &philo->own_fork);
	printf("left_fork = %p\n", &philo->left_fork);
	printf("death_lock = %p\n", philo->death_lock);
	printf("print_lock = %p\n", philo->print_lock);
	printf("prev = %p\n", philo->prev);
	printf("next = %p\n", philo->next);
	printf("-------------------------------------------\n");
}