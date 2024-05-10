/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:04:49 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/10 15:31:25 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h> 
#include <unistd.h>


# define FAIL 1
# define SUCCESS 0

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*own_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*print_lock;
	int				meals_eaten;
	size_t			last_meal;
	struct s_philo	*prev;
	struct s_philo	*next;
}				t_philo;

typedef struct s_data
{
	int				philo_nb;
	long			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	int				meals;
	size_t			time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	print;
	int				is_dead;
	t_philo			*philos;
	pthread_t		observer;
}				t_data;

/*		FREE		*/
void	ft_free_all(t_data *data);
void	ft_destroy(t_data *data);

/*		INIT		*/
void	ft_init_data(t_data *data);
void	ft_init_philo_forks(t_data *data, pthread_mutex_t *forks, t_philo *cur, int i);
int		ft_init_philos(t_data *data);

/*		PARSING_UTILS		*/
pthread_mutex_t	*ft_set_forks(t_data *data);

/*		PARSING		*/
int		ft_parsing_args(int ac, char **av, t_data *data);

/*		REMOVE		*/
void	ft_print_philos(t_data *data);

/*		SIMUL_UTILS		*/
int		ft_philo_thread(t_data *data, t_philo *philo);
int		ft_create_threads(t_data *data, t_philo *cur);
int		ft_join_threads(t_data *data);

/*		SIMULATION		*/
void	*ft_routine(void *arg);
void	*ft_observer(void *arg);
int		ft_launch_simulation(t_data *data);

/*		UTILS		*/
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);
size_t	ft_get_time(void);

#endif