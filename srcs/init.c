/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:46:19 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/16 23:29:36 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	init_data(char **av)
{
	dinner()->n_eats = INT_MAX;
	if (av[5] != NULL)
		dinner()->n_eats = ft_atol(av[5]);
	dinner()->n_philos = ft_atol(av[1]);
	dinner()->eat_time = ft_atol(av[3]);
	dinner()->die_time = ft_atol(av[2]);
	dinner()->sleep_time = ft_atol(av[4]);
	dinner()->cur_time = my_time();
	dinner()->forks = create_forks(sizeof(t_fork) * dinner()->n_philos);
	dinner()->philos = create_philos(sizeof(t_philo) * dinner()->n_philos);
	pthread_mutex_init(&dinner()->global , NULL);
	if (!dinner()->philos || !dinner()->forks)
		return (false);
	return (true);
}

t_fork *create_forks(size_t bytes)
{
	t_fork *fork;
	int	i;

	fork = malloc(bytes);
	if (!fork)
	{
		error("Malloc error");
		return (NULL);
	}
	i = 0;
	while(i < dinner()->n_philos)
	{
		fork[i].id = i + 1;
		pthread_mutex_init(&(fork[i].in_use), NULL);
		i++;
	}
	return(fork);
}

t_philo *create_philos(size_t bytes)
{
	t_philo *philo;
	int		i;

	philo = malloc(bytes);
	if (!philo)
	{
		error("Malloc error");
		return (NULL);
	}
	i = 0;
	while(i < dinner()->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].left = &(dinner()->forks[i]);
		philo[i].right = &(dinner()->forks[(i + 1) % dinner()->n_philos]);
		i++;
	}
	return(philo);
}