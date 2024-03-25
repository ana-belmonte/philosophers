/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:28:24 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/25 17:49:07 by aaires-b         ###   ########.fr       */
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
	int		len;

	i = 0;
	a = 0;
	len = 0;
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
		len++;
		if (len > 10 || a > INT_MAX)
			return (-1);
	}
	return (a);
}

unsigned int my_time()
{
	struct timeval time;
	long long int cur_time;
	
	gettimeofday(&time, NULL);
	cur_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return(cur_time);
}

unsigned int get_time()
{
	int a ;
	pthread_mutex_lock(&dinner()->global);
	a = my_time();
	pthread_mutex_unlock(&dinner()->global);
	return(a);
}

void my_sleep(unsigned int time, int action_time)
{
	while(get_time() < time + action_time)
	{
		if(getter(&dinner()->finish, 1, &dinner()->global))
			break ;
		usleep(100);
		continue ;
	}
}

int getter(void *info, int type, pthread_mutex_t *mutex)
{
	int a = 0;
	pthread_mutex_lock(mutex);
	if(type == 1)
		a = *(int*)info;
	else if(type == 2)
	{
		a = *(unsigned int*)info;
	}
	pthread_mutex_unlock(mutex);
	return(a);
}

void setter(void *info,	int value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*(int*)info = value;
	pthread_mutex_unlock(mutex);
}