/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:04:49 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/14 13:53:44 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h> 
#include <unistd.h>
#include <stdbool.h>


# define FAIL 1
# define SUCCESS 0

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*print_lock;
	int				meals_eaten;
	size_t			last_meal;
	int				philo_nb;
	int				is_dead;
	int				meals;
	long			start_time;
	size_t			*time_to_die;
	size_t			*time_to_eat;
	size_t			*time_to_sleep;
	struct s_philo	*prev;
	struct s_philo	*next;
}				t_philo;

typedef struct s_data
{
	int				philo_nb;
	long			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	print;
	int				is_dead;
	t_philo			**philos;
	pthread_t		observer;
}				t_data;

/*		FREE		*/
void	ft_free_philos(t_data *data);
void	ft_destroy(t_data *data);
void	ft_free_rest(t_data *data);

/*		INIT		*/
int		ft_init_data(t_data *data);
void	ft_init_philo_forks(t_data *data, pthread_mutex_t *forks, t_philo *cur, int i);
int		ft_init_philos(t_data *data);

/*		PARSING_UTILS		*/
int	ft_set_forks(t_data *data);

/*		PARSING		*/
int		ft_parsing_args(int ac, char **av, t_data *data);

/*		REMOVE		*/
void	ft_print_philos(t_data *data);
void	ft_print_data(t_data *data);
void	ft_print_philo_2(t_philo *philo);

/*		ROUTINE FUNCTIONS	*/
void	ft_thinking(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	ft_eating(t_philo *philo);

/*		SIMUL_UTILS		*/
void 	ft_print_message(t_philo *philo, char *message);
bool 	ft_death_check(t_philo *philo);
int		ft_create_threads(t_data *data, t_philo *cur);
int		ft_join_and_free_threads(t_data *data);

/*		SIMULATION		*/
void	*ft_routine(void *arg);
void	*ft_observer(void *arg);
int		ft_launch_simulation(t_data *data);

/*		UTILS		*/
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);
size_t	ft_get_time(void);

#endif