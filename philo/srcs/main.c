/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:24:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 15:09:01 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void ft_join_and_free(t_philo **philos, int philo_nb)
{
	int i;

	i = 0;
	while (i < philo_nb)
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo_nb)
	{
		if (philos[i])
			free(philos[i]);
		i++;
	}
	if (philos)
		free(philos);
}

static int ft_parse_args(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (FAIL);
	}
	data->philo_nb = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meal_nb = ft_atoi(av[5]);
	else
		data->meal_nb = -1;
	return (SUCCESS);
}

static void	ft_print(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep(500);
	pthread_mutex_lock(philo->print);
	printf("Hello from thread %d\n", philo->id);
	pthread_mutex_unlock(philo->print);
}

static int ft_init_philos(t_data *data)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * data->philo_nb);
	if (!philos)
		return (FAIL);
	while (i < data->philo_nb)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (FAIL);
		philos[i]->id = i;
		philos[i]->print = &data->print;
		pthread_create(&philos[i]->thread, NULL, (void *) ft_print, (void *)philos[i]); //to protect
		i++;
	}
	data->philos = philos;
	return (SUCCESS);
}

int main(int ac, char **av)
{
	t_data 	data;

	ft_parse_args(ac, av, &data);
	pthread_mutex_init(&data.print, NULL);
	if (ft_init_philos(&data) == FAIL)
		return (FAIL);
	ft_join_and_free(data.philos, data.philo_nb);
	pthread_mutex_destroy(&data.print);
	return (0);
}