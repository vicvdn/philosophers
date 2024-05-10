/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:56:55 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/10 10:40:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_data(t_data *data)
{
	data->observer = 0;
	data->philo_nb = 0;
	data->start_time = 0;
	data->death_flag = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->meals = -1; //if meals is not set, it will be -1
	data->philos = NULL;
	data->forks = ft_set_forks(data);
	if (!data->forks)
		exit(FAIL);
}

void	ft_init_philo_forks(t_data *data, pthread_mutex_t *forks, t_philo *cur, int i)
{
	cur->own_fork = &forks[i];
	if (i == data->philo_nb - 1)
		cur->left_fork = &forks[0];
	else
		cur->left_fork = &forks[i + 1];
}

static t_philo	*ft_fill_philo(t_data *data, t_philo *cur,
	t_philo *prev, int i)
{
	cur->id = i;
	cur->meals_eaten = 0;
	cur->last_meal = 0;
	if (i == 0)
	{
		data->philos = cur;
		cur->prev = NULL;
		cur->left_fork = NULL;
	}
	else
	{
		prev->next = cur;
		cur->prev = prev;
		cur->left_fork = NULL;
	}
	cur->own_fork = NULL;
	cur->next = NULL;
	return (cur);
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
		cur->print = &data->print;
		prev = cur;
		cur = cur->next;
		i++;
	}
	return (SUCCESS);
}
