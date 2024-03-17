/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:16:34 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/16 23:29:41 by aaires-b         ###   ########.fr       */
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
# include <sys/time.h>

typedef struct s_fork
{
	int				id;
	int picked;
	pthread_mutex_t	in_use;
}	t_fork;

typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	int		eating;
	int		sleeping;
	int		thinking;
	int 		died;
	int			n_eats;
	long		last_time_eaten;
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
	unsigned int	cur_time;
	int		finish;
	pthread_mutex_t global;
	t_philo	*philos;
	t_fork	*forks;
}	t_data;


// MAIN

t_data	*dinner(void);
bool	init_data(char **av);
t_philo	*create_philos(size_t bytes);
t_fork	*create_forks(size_t bytes);
//ACTIONS 

void think(int id);
void eat(t_philo *philo);
int pick_up_forks(t_philo *philo);
void sleeping(int id);
void put_down_forks(t_philo *philo);
bool check_deaths(t_philo *philo);

/// UTILS

long			ft_atol(char *str);
unsigned int	my_time();
void my_sleep(unsigned int time, int action_time, t_philo *philo);
void			error(char *str);

/// PARSING 

bool	parse_info(char **av);

// free

void free_all();

// routine
void start();


#endif