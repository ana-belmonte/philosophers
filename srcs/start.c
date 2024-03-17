/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:33:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/17 10:32:51 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void routine(t_philo *philo)
{
	while(1)
	{
		if(dinner()->finish)
			return ;
		//if((philo->id) % 2 != 0)
			//usleep(2/1000);
		if(pick_up_forks(philo))
		{
			if(dinner()->finish)
				return ;
			eat(philo);
			if(dinner()->finish)
				return ;
			put_down_forks(philo);
			if(dinner()->finish)
				return ;
			sleeping(philo->id);
			if(dinner()->finish)
				return ;
			think(philo->id);
			if (dinner()->finish)
				return ;
		}
		else
			put_down_forks(philo);
	}
}

void start()
{
	int i;

	
	i = 0;
	while(i < dinner()->n_philos)
	{
		//printf("%lu\n", dinner()->philos[i].philo);
		pthread_create(&(dinner()->philos[i].philo), NULL, (void*)routine, &dinner()->philos[i]);
		i++;
	}
	i = 0;
	while(i < dinner()->n_philos)
	{
		pthread_join(dinner()->philos[i].philo, NULL);
		i++;
	}
	free_all();
}