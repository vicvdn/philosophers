/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:33 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/14 15:59:36 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <string.h>

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
	int				meals;
	long			start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_lock;
	int				is_dead;
	t_philo			**philos;
}				t_data;

/*		FREE		*/
void	ft_join_and_free(t_philo **philos, int philo_nb);
void	ft_free_all(t_data *data);

/*		INIT		*/
int		ft_init_rest_data(t_data *data);

/*		PARSING		*/
int		ft_parse_args(int ac, char **av, t_data *data);

/*		UTILS		*/
int		ft_atoi(const char *str);

#endif