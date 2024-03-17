/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:11:21 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/16 23:32:14 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
}

void free_mutexes(t_fork *forks)
{
	int i;

	i = 0;
	while(i < dinner()->n_philos)
	{
		pthread_mutex_destroy(&forks[i].in_use);
		i++;
	}
	pthread_mutex_destroy(&dinner()->global);
}

void free_all()
{
	free_mutexes(dinner()->forks);
	free(dinner()->forks);
	free(dinner()->philos);
}