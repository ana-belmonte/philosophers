/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:16:34 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/25 19:37:33 by aaires-b         ###   ########.fr       */
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
	int				picked;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	// int		eating;
	// int		sleeping;
	// int		thinking;
	// int 		died;
	int			n_eats;
	int			f_all;
	unsigned int last_time_eaten;
	t_fork		*right;
	t_fork		*left;
	int forks_count;
}	t_philo;

typedef struct s_data
{
	unsigned int	eat_time;
	unsigned int	die_time;
	unsigned int	sleep_time;
	int		n_philos;
	int		n_eats;
	unsigned int	start_time;
	int		finish;
	int		start;
	int flag;
	pthread_mutex_t global;
	pthread_mutex_t m_fin;
	pthread_mutex_t prints;
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
int eat(t_philo *philo);
int pick_up_forks(t_philo *philo);
void sleeping(int id);
void put_down_forks(t_philo *philo);
int pick_up_forks2(t_philo *philo);
int getter(void *info, int type, pthread_mutex_t *mutex);
void setter(void *info, int value, pthread_mutex_t *mutex);

/// UTILS

long			ft_atol(char *str);
unsigned int	my_time();
void my_sleep(unsigned int time, int action_time);
void			error(char *str);
unsigned int get_time();
/// PARSING 

bool	parse_info(char **av);

// free

void free_all();

// routine
void start();

void check_stop(t_data *data);

#endif