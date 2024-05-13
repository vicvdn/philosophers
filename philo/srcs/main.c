/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:38 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/13 11:06:24 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data			*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (FAIL);
	if (ft_parsing_args(ac, av, data) == FAIL)
		return (FAIL);
	if (ft_init_philos(data) == FAIL)
		return (FAIL);
	if (ft_launch_simulation(data) == FAIL)
		return (FAIL);
	// ft_print_philos(data);
	ft_destroy(data);
	ft_free_all(data);
	return (0);
}
