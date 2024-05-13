/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:49 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/13 11:44:01 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_fill_data(t_data *data, char *str, int i)
{
	if (i == 2)
	{
		data->time_to_die = ft_atoi(str);
		if (data->time_to_die <= 0)
			return (free(data), FAIL);
	}
	else if (i == 3)
	{
		data->time_to_eat = ft_atoi(str);
		if (data->time_to_eat <= 0)
			return (free(data), FAIL);
	}
	else if (i == 4)
	{
		data->time_to_sleep = ft_atoi(str);
		if (data->time_to_sleep <= 0)
			return (free(data), FAIL);
	}
	if (i == 5)
		data->meals = ft_atoi(str);
	return (SUCCESS);
}

int	ft_parsing_args(int ac, char **av, t_data *data)
{
	int		i;

	if (ac < 5 || ac > 6)
		return (free(data), FAIL);
	i = 1;
	if (ft_init_data(data) == FAIL)
		return (ft_free_all(data), FAIL);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == FAIL)
			return (free(data), FAIL);
		if (i == 1)
		{
			data->philo_nb = ft_atoi(av[i]);
			if (data->philo_nb < 1 || data->philo_nb > 200)
				return (free(data), FAIL);
		}
		else if (i > 1)
		{
			if (ft_fill_data(data, av[i], i) == FAIL)
				return (free(data), FAIL);
		}
		i++;
	}
	return (SUCCESS);
}
