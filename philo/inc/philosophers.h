/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:33 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/17 11:12:11 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <stdbool.h>

# define FAIL 1
# define SUCCESS 0
# define YES 1
# define NO 0

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				philo_nb;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				meals;
	long			start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death_lock;
	int				other;
	pthread_mutex_t	own_fork;
	long			last_meal;
	struct s_data	*data;
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
	pthread_mutex_t	death_lock;
	pthread_mutex_t	read;
	pthread_mutex_t	time;
	pthread_t		observer;
	int				is_dead;
	t_philo			**philos;
}				t_data;

/*		FREE		*/
void			ft_join_and_free(t_data *data);
void			ft_mutex_destroy(t_data *data);

/*		INIT		*/
void			ft_fill_philo(t_philo *philo, t_data *data, int i);
int				ft_init_philos(t_data *data);
pthread_mutex_t	*ft_set_forks(t_data *data, int philo_nb);
int				ft_init_rest_data(t_data *data);

/*		PARSING		*/
int				ft_parse_args(int ac, char **av, t_data *data);

/*		REMOVE		*/

/*		ROUTINE		*/
void			ft_thinking(t_philo *philo);
void			ft_sleeping(t_philo *philo);
void			ft_eating(t_philo *philo);
void			*ft_routine(void *arg);

/*		SIMULATION	*/
int				ft_launch_simulation(t_data *data);

/*		UTILS		*/
int				ft_atoi(const char *str);
size_t			ft_get_time_from_start(t_philo *philo);
size_t			ft_get_start_time(void);
void			ft_print_message(t_philo *philo, char *message);
void			ft_usleep(t_philo *philo, size_t time);
size_t 			ft_get_time(void);

#endif