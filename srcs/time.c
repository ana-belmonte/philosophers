/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:58:13 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/27 14:58:47 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

unsigned int	my_time(void)
{
	struct timeval	time;
	long long int	cur_time;

	gettimeofday(&time, NULL);
	cur_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (cur_time);
}

unsigned int	get_time(void)
{
	int	a;

	pthread_mutex_lock(&dinner()->glb);
	a = my_time();
	pthread_mutex_unlock(&dinner()->glb);
	return (a);
}

void	my_sleep(unsigned int time, int action_time)
{
	while (get_time() < time + action_time)
	{
		if (getter(&dinner()->finish, 1, &dinner()->glb))
			break ;
		usleep(100);
		continue ;
	}
}
