/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:13:32 by ubuntu            #+#    #+#             */
/*   Updated: 2024/05/08 09:40:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (FAIL);
	if (ft_parsing_args(ac, av, data) == FAIL)
		return (FAIL);
	(void)av;
	free(data);
	return (0);
}