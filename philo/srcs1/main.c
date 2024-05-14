/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:38 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 14:46:24 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	main(int ac, char **av)
// {
// 	t_data			*data;

// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (FAIL);
// 	if (ft_parsing_args(ac, av, data) == FAIL)
// 		return (FAIL);
// 	if (ft_init_philos(data) == FAIL)
// 		return (FAIL);
// 	if (ft_launch_simulation(data) == FAIL)
// 		return (FAIL);
// 	// ft_print_philos(data);
// 	// ft_free_philos(data);
// 	// ft_destroy(data);
// 	if (ft_join_and_free_threads(data) == FAIL)
// 		return (FAIL);
// 	return (0);
// }

/*On va recreer les threads des philos et leur faire ecrire chacun un message
avec un mutex sur le print et en profiter pour faire en sorte que data->philos
soit un tableau malloc*/

void	ft_free_test(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	free(data->forks);
	free(data);
}

static void	ft_print(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i != data->philos[i]->id)
		i++;
	pthread_mutex_lock(&data->print);
	printf("Hello from thread %d\n", data->philos[i]->id);
	pthread_mutex_unlock(&data->print);
}

// int	main(int ac, char **av)
// {
// 	t_data			*data;
// 	t_philo			**philos;
// 	int				i;

// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (FAIL);
// 	if (ft_parsing_args(ac, av, data) == FAIL)
// 		return (FAIL);
// 	data->philo_nb = ft_atoi(av[1]);
// 	philos = malloc(sizeof(t_philo *) * data->philo_nb);
// 	if (!data->philos)
// 		return (FAIL);
// 	i = 0;
// 	while (i < data->philo_nb)
// 	{
// 		philos[i] = malloc(sizeof(t_philo));
// 		if (!philos[i])
// 			return (FAIL);
// 		philos[i]->id = i;
// 	}
// 	while (i < data->philo_nb)
// 	{
// 		if (pthread_create(&(philos[i]->thread), NULL, (void *)ft_print, (void *)data))
// 			return (FAIL);
// 		i++;
// 	}
// 	data->philos = philos;
// 	i = 0;
// 	ft_free_test(data);
// 	while (i < data->philo_nb)
// 	{
// 		if (pthread_join(philos[i]->thread, NULL))
// 			return (FAIL);
// 		i++;
// 	}
// 	return (SUCCESS);
// }