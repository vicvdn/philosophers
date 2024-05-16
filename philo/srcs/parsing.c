/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:12:13 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/16 17:22:01 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int ft_fill_data(t_data *data, char *str, int i)
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

int ft_parse_args(int ac, char **av, t_data *data)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (FAIL);
	}
	data->philo_nb = ft_atoi(av[1]);
	if (data->philo_nb <= 0 || data->philo_nb > 200)
		return (printf("Error: wrong number of philosophers\n"), FAIL);
	i = 2;
	while (i < ac)
	{
		if (ft_fill_data(data, av[i], i) == FAIL)
			return (FAIL);
		else
			i++;
	}
	return (SUCCESS);
}