/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:33:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/27 14:40:45 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	routine(t_philo *philo)
{
	while (!getter(&dinner()->start, 1, &dinner()->glb))
		continue ;
	setter(&philo->lst_eaten, my_time(), &dinner()->glb);
	if (philo->id % 2 != 0)
		usleep(1000);
	while (!getter(&dinner()->finish, 1, &dinner()->glb))
	{
		if (eat(philo))
		{
			sleeping(philo->id);
			think(philo->id);
		}
		usleep(100);
	}
}

void	start(void)
{
	int	i;

	i = 0;
	while (i < dinner()->n_philos)
	{
		pthread_create(&(dinner()->philos[i].phl), NULL, 
			(void *)routine, &dinner()->philos[i]);
		i++;
	}
	dinner()->start_time = my_time();
	setter(&dinner()->start, 1, &dinner()->glb);
	i = 0;
	check_stop(dinner());
	while (i < dinner()->n_philos)
	{
		pthread_join(dinner()->philos[i].phl, NULL);
		i++;
	}
	free_all();
}
