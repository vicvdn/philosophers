/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:56:55 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/13 15:21:54 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_data(t_data *data)
{
	data->observer = 0;
	data->philo_nb = 0;
	data->start_time = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->meals = -1; //if meals is not set, it will be -1
	data->is_dead = 0;
	if (pthread_mutex_init(&data->death_lock, NULL))
		return (ft_free_all(data), FAIL);
	if (pthread_mutex_init(&data->print, NULL))
		return (ft_free_all(data), FAIL);
	data->philos = NULL;
	data->forks = ft_set_forks(data);
	if (!data->forks)
		return (FAIL);
	return (SUCCESS);
}

void	ft_init_philo_forks(t_data *data, pthread_mutex_t *forks, t_philo *cur, int i)
{
	cur->own_fork = forks[i];
	if (i == data->philo_nb - 1)
		cur->left_fork = forks[0];
	else
		cur->left_fork = forks[i + 1];
}

static t_philo	*ft_fill_philo(t_data *data, t_philo *cur,
	t_philo *prev, int i)
{
	cur->id = i;
	cur->meals_eaten = 0;
	cur->last_meal = 0;
	cur->is_dead = (data->is_dead);
	cur->meals = data->meals;
	cur->time_to_die = &data->time_to_die;
	cur->time_to_eat = &data->time_to_eat;
	cur->time_to_sleep = &data->time_to_sleep;
	cur->philo_nb = data->philo_nb;
	if (i == 0)
	{
		data->philos = cur;
		cur->prev = NULL;
		// cur->left_fork = NULL;
	}
	else
	{
		prev->next = cur;
		cur->prev = prev;
		// cur->left_fork = NULL;
	}
	// cur->own_fork = NULL;
	cur->next = NULL;
	return (cur);
}

static void ft_init_rest_philo(t_data *data, t_philo *cur)
{
	cur->death_lock = &data->death_lock;
	cur->print_lock = &data->print;
}

int	ft_init_philos(t_data *data)
{
	t_philo	*cur;
	t_philo	*prev;
	int		i;

	i = 0;
	prev = NULL;
	while (i < data->philo_nb)
	{
		cur = malloc(sizeof(t_philo));
		if (!cur)
			return (FAIL);
		cur = ft_fill_philo(data, cur, prev, i);
		ft_init_philo_forks(data, data->forks, cur, i);
		ft_init_rest_philo(data, cur);
		prev = cur;
		cur = cur->next;
		i++;
	}
	return (SUCCESS);
}
