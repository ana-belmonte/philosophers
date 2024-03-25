/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:33:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/25 17:30:40 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


void routine(t_philo *philo)
{
	while(!getter(&dinner()->start, 1, &dinner()->global))
 		continue ;
	setter(&philo->last_time_eaten, my_time(), &dinner()->global);
	if(philo->id % 2 != 0)
	{
		usleep(dinner()->n_philos);
		//setter(&dinner()->flag, 1, &dinner()->global);
	}
	while(!getter(&dinner()->finish, 1, &dinner()->global))
	{
		if(pick_up_forks(philo))
		{
			if(eat(philo))
			{
				put_down_forks(philo);
				sleeping(philo->id);
				think(philo->id);
			}
		}
		usleep(100);
		//put_down_forks(philo);
	}
}

void start()
{
	int i;
	
	i = 0;
	while(i < dinner()->n_philos)
	{
		//printf("%lu\n", dinner()->philos[i].philo);
		dinner()->philos[i].last_time_eaten = my_time();
		pthread_create(&(dinner()->philos[i].philo), NULL, (void*)routine, &dinner()->philos[i]);
		i++;
	}
	dinner()->start_time = my_time();
	setter(&dinner()->start, 1, &dinner()->global);
	i = 0;
	check_stop(dinner());
	while(i < dinner()->n_philos)
	{
		pthread_join(dinner()->philos[i].philo, NULL);
		i++;
	}
	free_all();
}