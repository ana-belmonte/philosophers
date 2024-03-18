/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:33:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/18 22:09:02 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void routine(t_philo *philo)
{
	while(!dinner()->finish)
	{
		//if((philo->id) % 2 != 0)
			//usleep(2/1000);
		if(pick_up_forks(philo))
		{
			eat(philo);
			put_down_forks(philo);
			sleeping(philo->id);
			think(philo->id);
			if(died(philo->id))
				break ;
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