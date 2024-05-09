/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:04:49 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/09 14:56:58 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


# define FAIL 1
# define SUCCESS 0

typedef struct s_philo
{
	int				id;
	int				own_fork;
	int				left_fork;
	pthread_t		thread;
	int				meals_eaten;
	size_t			last_meal;
	struct s_philo	*prev;
	struct s_philo	*next;
}				t_philo;

typedef struct s_data
{
	pthread_t		observer;
	int				philo_nb;
	long			start_time;
	int				death_flag;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				*forks;
	int				meals;
	t_philo			*philos;
}				t_data;

/*		FREE		*/
void	ft_free_all(t_data *data);

/*		PARSING		*/
int		ft_parsing_args(int ac, char **av, t_data *data);
int		ft_init_philos(t_data *data);

/*		REMOVE		*/
void	ft_print_philos(t_data *data);

/*		SIMUL_UTILS		*/
int		ft_philo_thread(t_data *data, t_philo *philo);
int		ft_create_threads(t_data *data);
int		ft_join_threads(t_data *data);

/*		SIMULATION		*/
void	ft_routine(void *arg);
void	*ft_observer(void *arg);
int		ft_launch_simulation(t_data *data);

/*		UTILS		*/
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);


#endif