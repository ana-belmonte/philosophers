/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:56:54 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/27 14:57:37 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	lock_forks(int id)
{
	if (getter(id, 1, &dinner()->glb) % 2 != 0)
	{
		pthread_mutex_lock(&dinner()->philos[id - 1].left->fork);
		print("has taken a fork", dinner()->philos[id - 1].id);
		pthread_mutex_lock(&dinner()->philos[id - 1].right->fork);
		print("has taken a fork", dinner()->philos[id - 1].id);
	}
	else
	{
		pthread_mutex_lock(&dinner()->philos[id - 1].right->fork);
		print("has taken a fork", dinner()->philos[id - 1].id);
		pthread_mutex_lock(&dinner()->philos[id - 1].left->fork);
		print("has taken a fork", dinner()->philos[id - 1].id);
	}
}

void	put_down_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
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
