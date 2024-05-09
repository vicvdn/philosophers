/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:04:49 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/09 11:38:02 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>


# define FAIL 1
# define SUCCESS 0

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	struct s_philo	*prev;
	struct s_philo	*next;
}				t_philo;

typedef struct s_data
{
	int			philo_nb;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			meals;
	t_philo		*philos;
}				t_data;

/*		FREE		*/
void	ft_free_all(t_data *data);

/*		PARSING		*/
int		ft_parsing_args(int ac, char **av, t_data *data);
int		ft_init_philos(t_data *data);

/*		REMOVE		*/
void	ft_print_philos(t_data *data);

/*		UTILS		*/
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);


#endif