/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:38 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 11:54:40 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (FAIL);
	printf("Data allocated\n");
	if (ft_parsing_args(ac, av, data) == FAIL)
		return (FAIL);
	printf("Data parsed\n");
	if (ft_init_philos(data) == FAIL)
		return (FAIL);
	printf("Philosophers initialized\n");
	ft_print_philos(data);
	printf("Philosophers printed\n");
	(void)av;
	ft_free_all(data);
	return (0);
}
