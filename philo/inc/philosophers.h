/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:33 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 15:03:51 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

# define FAIL 1
# define SUCCESS 0

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*print;
}				t_philo;

typedef struct s_data
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_nb;
	pthread_mutex_t	print;
	t_philo			**philos;
}				t_data;

/*		UTILS		*/
int		ft_atoi(const char *str);

#endif