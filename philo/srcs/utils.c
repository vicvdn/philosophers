/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:12:05 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/10 10:11:58 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FAIL);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	ft_char_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ft_char_isdigit(nptr[i]) && nptr[i])
		res = (res * 10) + (nptr[i++] - 48);
	return (sign * res);
}

size_t	ft_get_time(void)
{
	struct timeval	time;
	size_t			res;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}