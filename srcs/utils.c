/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:28:24 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/30 13:41:07 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	i;
	long	a;

	i = 0;
	a = 0;
	if (!ft_isdigit(str))
		return (-1);
	i = ft_isspace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - 48);
		i++;
		if (a > INT_MAX)
			return (-1);
	}
	return (a);
}

int	getter(void *info, int type, pthread_mutex_t *mutex)
{
	int	a;

	a = 0;
	pthread_mutex_lock(mutex);
	if (type == 1)
		a = *(int *)info;
	else if (type == 2)
	{
		a = *(unsigned int *)info;
	}
	pthread_mutex_unlock(mutex);
	return (a);
}

void	setter(void *info,	int value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*(int *)info = value;
	pthread_mutex_unlock(mutex);
}
