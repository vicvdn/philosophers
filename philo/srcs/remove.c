/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:34:39 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/09 12:07:25 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_philos(t_data *data)
{
	t_philo	*cur;

	cur = data->philos;
	if (!cur)
	{
		printf("No philosophers\n");
		return ;
	}
	printf("-----Philo\t Meals_eaten\t Prev\t\t Cur\t\t Next\t\t -----\n");
	while (cur)
	{
		printf("----- %d\t\t\t", cur->id);
		printf(" %d\t", cur->meals_eaten);
		printf(" %p\t", cur->prev);
		if (cur->prev == NULL)
			printf("\t");
		printf(" %p\t", cur);
		printf(" %p\t\n", cur->next);
		// printf("----- %d\t\t\t %d\t\t\t %d\t\t %d\t\t -----\n", cur->id, cur->meals_eaten, cur->prev->id, cur->next->id);
		cur = cur->next;
	}
}