/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:14:07 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/15 14:50:56 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_launch_simulation(t_data *data)
{
	if (ft_init_philos(data) == FAIL)
		return (FAIL);
	// printf("COUCOUCOUCOUC\n");
	ft_join_and_free(data);
	return (SUCCESS);
}
