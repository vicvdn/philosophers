/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:14:07 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 11:22:46 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_launch_simulation(t_data *data)
{
	if (ft_init_philos(data) == FAIL)
		return (FAIL);
	ft_join_and_free(data->philos, data->philo_nb);
	return (SUCCESS);
}