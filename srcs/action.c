/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:08:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/17 10:25:56 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void think(int id)
{
	printf("%u Philosopher number %d is thinking\n",(my_time() - dinner()->cur_time), id);
}

int pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->in_use);
	if (!philo->left->picked)	
	{
		philo->left->picked = 1;
		printf("%u Philosopher number %d picked up fork\n", (my_time() - dinner()->cur_time), philo->id);
		pthread_mutex_unlock(&philo->left->in_use);
		pthread_mutex_lock(&philo->right->in_use);
		if (!philo->right->picked) 
		{
			philo->right->picked = 1;
			printf("%u Philosopher number %d picked up fork\n", (my_time() - dinner()->cur_time), philo->id);
			pthread_mutex_unlock(&philo->right->in_use);
			return (1);
			
		}
		else
			pthread_mutex_unlock(&philo->right->in_use);
	}
	else
		pthread_mutex_unlock(&philo->left->in_use);
	return(0);
}

void eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->in_use);
	if(philo->left->picked)
	{
		pthread_mutex_unlock(&philo->left->in_use);
		pthread_mutex_lock(&philo->right->in_use);
		if(philo->right->picked)
		{
			philo->n_eats++;
			printf("%u Philosopher number %d is eating \n", (my_time() - dinner()->cur_time), philo->id);
			philo->last_time_eaten = my_time();
			my_sleep(my_time(), dinner()->eat_time, philo);
			if(check_deaths(philo))
				return ;
			pthread_mutex_unlock(&philo->right->in_use);
		}
		else
			pthread_mutex_unlock(&philo->right->in_use);
	}
	else
		pthread_mutex_unlock(&philo->left->in_use);
}

void put_down_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->right->in_use);
	philo->right->picked = 0;	
	pthread_mutex_unlock(&philo->right->in_use);
	pthread_mutex_lock(&philo->left->in_use);
	philo->left->picked = 0;
	pthread_mutex_unlock(&philo->left->in_use);
	if(check_deaths(philo))
		return ;
}

void sleeping(int id)
{
	printf("%u Philosopher number %d is sleeping \n", (my_time() - dinner()->cur_time), id);
	my_sleep(my_time(), dinner()->sleep_time, &dinner()->philos[id -1]);
	if(check_deaths(&dinner()->philos[id - 1]))
		return ;
}

bool	check_deaths(t_philo *philo)
{
	bool is_finished;
    pthread_mutex_lock(&dinner()->global);
    is_finished = dinner()->finish;
	if (is_finished || my_time() - philo->last_time_eaten == dinner()->die_time)
	{
		dinner()->finish = 1;
		printf("%u Philosopher number %d is dead \n", (my_time() - dinner()->cur_time), philo->id);
		pthread_mutex_unlock(&dinner()->global);
		return (true);
	}
	else if(dinner()->n_eats == philo->n_eats)
	{
		pthread_mutex_unlock(&dinner()->global);
		return (true);
	}
	else
		pthread_mutex_unlock(&dinner()->global);
	return(false);
}
