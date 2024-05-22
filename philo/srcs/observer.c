/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:17:04 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/21 15:05:30 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->death_lock);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->death_lock);
	ft_print_dead_message(philo, "died");
}

static int	ft_check_philos(t_data *data, int i)
{
	pthread_mutex_lock(&data->read);
	if (data->philos[i]->last_meal == -1)
	{
		// pthread_mutex_lock(&data->time);
		if (ft_get_time() - data->start_time > data->time_to_die)
		{
			// pthread_mutex_unlock(&data->time);
			pthread_mutex_unlock(&data->read);
			ft_set_dead(data, data->philos[i]);
			return (1);
		}
		else
			pthread_mutex_unlock(&data->read);
		// pthread_mutex_unlock(&data->time);
		ft_usleep(data->philos[i], 10);
	}
	else
	{
		if (ft_get_time_from_start(data->philos[i]) - data->philos[i]->last_meal > data->time_to_die)
		{
			pthread_mutex_unlock(&data->read);
			ft_set_dead(data, data->philos[i]);
			return (1);
		}
		else
			pthread_mutex_unlock(&data->read);
	}
	return (0);
}

static int	ft_all_meals_eaten(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (data->all_meals_eaten[i] != data->meals)
			return (NO);
		i++;
	}
	return (YES);
}

static int ft_check_meals(t_data *data, t_philo *philo)
{
	int	i = 0;
	if (data->meals != -1)
	{
		if (philo->meals == data->meals)
		{
			// printf("philo[%d]->meals: %d\n", philo->id + 1, philo->meals);
			// printf("data->meals: %d\n", data->meals);
			pthread_mutex_lock(&data->add_meals);
			if (data->all_meals_eaten && data->all_meals_eaten[philo->id] < data->meals)
				data->all_meals_eaten[philo->id] += data->meals;
			// while (i < data->philo_nb)
			// {
			// 	printf("data->all_meals_eaten[%d]: %d\n", i, data->all_meals_eaten[i]);
			// 	i++;
			// }
			// printf("--------------------------------------------------------\n");
			if (ft_all_meals_eaten(data) == YES)
			{
				pthread_mutex_unlock(&data->add_meals);
				return (STOP);
			}
			pthread_mutex_unlock(&data->add_meals);
		}
	}
	return (CONTINUE);
}

static void	ft_stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->death_lock);
}

void	*ft_observer(void *arg)
{
	int	i;
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_nb)
		{
			if (ft_check_philos(data, i) == 1)
				return (NULL);
			if (data->meals != -1)
			{
				if (ft_check_meals(data, data->philos[i]) == STOP)
				{
					ft_stop_simulation(data);
					free(data->all_meals_eaten);
					return (NULL);
				}
			}
			i++;
		}
	}
}
