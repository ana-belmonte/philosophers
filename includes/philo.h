/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:16:34 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/12 17:15:33 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	in_use;
}	t_fork;

typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	bool		eating;
	bool		sleeping;
	bool		thinking;
	t_fork		*right;
	t_fork		*left;

}	t_philo;

typedef struct s_data
{
	long	eat_time;
	long	die_time;
	long	sleep_time;
	int		n_philos;
	int		n_eats;
	t_philo	*philos;
	t_fork	*forks;
}	t_data;

/// UTILS

long	ft_atol(char *str);

/// PARSING 

bool	parse_info(char **av);

#endif