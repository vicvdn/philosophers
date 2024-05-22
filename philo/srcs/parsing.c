/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:12:13 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/22 17:55:56 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_check(long nb, const char *str)
{
	if (nb <= 0 || nb > INT_MAX)
		return (FAIL);
	return (SUCCESS);
}

static int	ft_fill_data(t_data *data, const char *str, int i)
{
	if (i == 2)
	{
		data->time_to_die = ft_atol(str);
		if (ft_check(data->time_to_die, str) == FAIL)
			return (FAIL);
	}
	else if (i == 3)
	{
		data->time_to_eat = ft_atol(str);
		if (ft_check(data->time_to_eat, str) == FAIL)
			return (FAIL);
	}
	else if (i == 4)
	{
		data->time_to_sleep = ft_atol(str);
		if (ft_check(data->time_to_sleep, str) == FAIL)
			return (FAIL);
	}
	if (i == 5)
	{
		data->meals = ft_atol(str);
		if (ft_check(data->meals, str) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

int	ft_parse_args(int ac, char **av, t_data *data)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (FAIL);
	}
	if (ft_len(av[1]) > 10)
		return (printf("Error: wrong number of philosophers\n"), FAIL);
	data->philo_nb = ft_atol(av[1]);
	if (ft_check(data->philo_nb, av[1]) == FAIL)
		return (printf("Error: wrong number of philosophers\n"), FAIL);
	i = 2;
	while (i < ac)
	{
		if (ft_len((const char *)av[i]) > 10)
			return (printf("Error: wrong argument\n"), FAIL);
		if (ft_fill_data(data, (const char *)av[i], i) == FAIL)
			return (FAIL);
		else
			i++;
	}
	if (ac == 5)
		data->meals = -1;
	return (SUCCESS);
}
