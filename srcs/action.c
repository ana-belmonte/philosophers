/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:08:04 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/29 19:10:43 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print(char *s, int id)
{
	if (!getter(&dinner()->finish, 1, &dinner()->glb))
	{
		pthread_mutex_lock(&dinner()->prints);
		printf("%u %d %s\n", (my_time() - dinner()->start_time), id, s);
		pthread_mutex_unlock(&dinner()->prints);
	}
}

void	think(int id)
{
	if (!getter(&dinner()->finish, 1, &dinner()->glb))
	{
		print("is thinking", id);
	}
}

int	eat(t_philo *philo)
{
	int	a;

	a = 0;
	if (!getter(&dinner()->finish, 1, &dinner()->glb))
	{
		lock_forks(philo->id);
		setter(&philo->n_eats, (philo->n_eats + 1), &dinner()->glb);
		if (!getter(&dinner()->finish, 1, &dinner()->glb))
			print("is eating", philo->id);
		a = my_time();
		setter(&philo->lst_eaten,
			getter(&a, 2, &dinner()->glb), &dinner()->glb);
		my_sleep(my_time(), dinner()->eat_time);
		put_down_forks(philo);
		return (1);
	}
	return (0);
}

void	sleeping(int id)
{
	if (!getter(&dinner()->finish, 1, &dinner()->glb))
	{
		if (!getter(&dinner()->finish, 1, &dinner()->glb))
			print("is sleeping", id);
		my_sleep(my_time(), dinner()->sleep_time);
	}
}
