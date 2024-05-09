/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:49 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 11:53:41 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_fill_data(t_data *data, char *str, int i)
{
	if (i == 2)
	{
		data->time_to_die = ft_atoi(str);
		if (data->time_to_die <= 0)
			return (FAIL);
	}
	else if (i == 3)
	{
		data->time_to_eat = ft_atoi(str);
		if (data->time_to_eat <= 0)
			return (FAIL);
	}
	else if (i == 4)
	{
		data->time_to_sleep = ft_atoi(str);
		if (data->time_to_sleep <= 0)
			return (FAIL);
	}
	if (i == 5)
		data->meals = ft_atoi(str);
	return (SUCCESS);
}

int	ft_parsing_args(int ac, char **av, t_data *data)
{
	int		i;

	if (ac < 5 || ac > 6)
		return (FAIL);
	i = 1;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == FAIL)
			return (FAIL);
		if (i == 1)
		{
			data->philo_nb = ft_atoi(av[i]);
			if (data->philo_nb < 1 || data->philo_nb > 200)
				return (FAIL);
			else
				return (SUCCESS);
		}
		else if (i > 1)
		{
			if (ft_fill_data(data, av[i], i) == FAIL)
				return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

static t_philo	*ft_alloc_fill_philo(t_data *data, t_philo *cur,
	t_philo *prev, int i)
{
	cur->id = i;
	cur->meals_eaten = 0;
	cur->last_meal = 0;
	if (i == 0)
	{
		data->philos = cur;
		cur->prev = NULL;
	}
	else
	{
		prev->next = cur;
		cur->prev = prev;
	}
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
		cur = ft_alloc_fill_philo(data, cur, prev, i);
		prev = cur;
		cur = cur->next;
		i++;
	}
	return (SUCCESS);
}
