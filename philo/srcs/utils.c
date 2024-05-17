/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:30:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/17 15:20:34 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

void	ft_print_message(t_philo *philo, char *message)
{
	long	time;

	time = ft_get_time_from_start(philo);
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->death_lock);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->death_lock);
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	pthread_mutex_unlock(&philo->data->death_lock);
	printf("%ld %d %s\n", time, philo->id + 1, message);
	pthread_mutex_unlock(&philo->data->print);
}
