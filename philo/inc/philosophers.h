/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:04:49 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/08 10:01:26 by ubuntu           ###   ########.fr       */
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
	
}				t_philo;

typedef struct s_data
{
	int			philo;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			meals;
}				t_data;


/*		UTILS		*/
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);

/*		PARSING		*/
int	ft_parsing_args(int ac, char **av, t_data *data);

#endif