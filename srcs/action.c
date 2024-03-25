/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:08:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/25 19:53:05 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void print(char *s, int id)
{
	pthread_mutex_lock(&dinner()->prints);
	printf("%u %d %s\n", (my_time() - dinner()->start_time), id, s);
	pthread_mutex_unlock(&dinner()->prints);
}

void think(int id)
{
	if(!getter(&dinner()->finish, 1, &dinner()->global))
	{
		print("is thinking", id);
	}
}


// int pick_up_forks(t_philo *philo)
// {
// 	if(!getter(&dinner()->finish, 1, &dinner()->global))
// 	{
// 		if (!getter(&philo->left->picked, 1, &philo->left->in_use) && !getter(&dinner()->finish, 1, &dinner()->global))	
// 		{
// 			print("has taken a fork", philo->id);
// 			setter(&philo->left->picked, 1, &philo->left->in_use);
// 		}
// 		if (!getter(&philo->right->picked, 1, &philo->right->in_use) && !getter(&dinner()->finish, 1, &dinner()->global)) 
// 		{
// 			setter(&philo->right->picked, 1, &philo->right->in_use);
// 			print("has taken a fork", philo->id);
// 			return (1);
// 		}
// 	}
// 	return(0);
// }

int eat(t_philo *philo)
{

	int a = 0;
	if(!getter(&dinner()->finish, 1, &dinner()->global))
	{
		if(getter(&philo->id, 1, &dinner()->global) % 2 != 0)
		{
			pthread_mutex_lock(&philo->left->fork);
			print("has taken a fork", philo->id);
			pthread_mutex_lock(&philo->right->fork);
			print("has taken a fork", philo->id);
		}
		else
		{
			pthread_mutex_lock(&philo->right->fork);
			print("has taken a fork", philo->id);
			pthread_mutex_lock(&philo->left->fork);
			print("has taken a fork", philo->id);
		}	
		setter(&philo->n_eats, (philo->n_eats + 1), &dinner()->global);
		print("is eating", philo->id);
		a = my_time();
		setter(&philo->last_time_eaten , 
				getter(&a, 2, &dinner()->global), &dinner()->global);
		my_sleep(my_time(), dinner()->eat_time);
		put_down_forks(philo);
		return(1);
	}
	return(0);
}

void put_down_forks(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->left->fork);
		pthread_mutex_unlock(&philo->right->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->right->fork);
		pthread_mutex_unlock(&philo->left->fork);
	}
}


void sleeping(int id)
{
	if(!getter(&dinner()->finish, 1, &dinner()->global))
	{
		if(!getter(&dinner()->finish, 1, &dinner()->global))
			print("is sleeping", id);
		my_sleep(my_time(), dinner()->sleep_time);
	}
}


void check_stop(t_data *data)
{
	int i;

	i = 0;
	while(1)
	{
		i = 0;
		while(i < data->n_philos)
		{
			if((int)get_time() - getter(&data->philos[i].last_time_eaten, 2, &dinner()->global) >= getter(&data->die_time, 2, &dinner()->global) 
				|| getter(&data->philos[i].n_eats, 1, &dinner()->global) >= getter(&data->n_eats, 1, &dinner()->global))
			{
				// printf("dif : %d\n", (int)get_time() - getter(&data->philos[i].last_time_eaten, 2, &dinner()->global));
				// printf("die time: %u\n", data->die_time);
				// printf("last time eaten: %u\n", data->philos[i].last_time_eaten);
				// printf("n eats philo: %i\n", data->philos[i].n_eats);
				// printf("n eats all: %i\n", data->n_eats);
				setter(&dinner()->finish, 1, &dinner()->global);
				print("has died", data->philos[i].id);
				return ; 
			}
			usleep(100);
		}
	}
}

