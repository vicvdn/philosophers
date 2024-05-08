/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:21:26 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/08 09:53:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_fill_data(t_data *data, char *str, int i)
{
	if (i == 1)
	{
		data->philo = ft_atoi(str);
		if (data->philo < 1)
			return (FAIL);
	}
	else if (i == 2)
		data->time_to_die = ft_atoi(str);
	else if (i == 3)
		data->time_to_eat = ft_atoi(str);
	else if (i == 4)
		data->time_to_sleep = ft_atoi(str);
	else if (i == 5)
		data->meals = ft_atoi(str);
	return (SUCCESS);
}

int	ft_parsing_args(int ac, char **av, t_data *data)
{
	int		i;
	
	if (ac < 5 || ac > 6)
		return (FAIL);
	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == FAIL)
			return (FAIL);
		if (ft_fill_data(data, av[i], i) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}