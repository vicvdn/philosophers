/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:31 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 15:13:39 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_all(t_data *data)
{
	t_philo	*cur;
	t_philo	*tmp;

	cur = data->philos;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	if (data->forks)
		free(data->forks);
	if (data)
		free(data);
}