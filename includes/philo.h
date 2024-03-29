/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:16:34 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/29 11:23:45 by aaires-b         ###   ########.fr       */
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
	int				id;
	int				n_eats;
	int				f_all;
	int				forks_count;
	unsigned int	lst_eaten;
	t_fork			*right;
	t_fork			*left;
	pthread_t		phl;
}	t_philo;

typedef struct s_data
{
	unsigned int	eat_time;
	unsigned int	die_time;
	unsigned int	start_time;
	unsigned int	sleep_time;
	int				n_philos;
	int				n_eats;
	int				finish;
	int				start;
	int				flag;
	pthread_mutex_t	glb;
	pthread_mutex_t	prints;
	t_philo			*philos;
	t_fork			*forks;
}	t_data;

// MAIN

t_data			*dinner(void);
bool			init_data(char **av);
t_philo			*create_philos(size_t bytes);
t_fork			*create_forks(size_t bytes);

//ACTIONS 

void			think(int id);
int				eat(t_philo *philo);
void			sleeping(int id);
void			put_down_forks(t_philo *philo);
void			lock_forks(int id);
/// UTILS

long			ft_atol(char *str);
unsigned int	my_time(void);
void			my_sleep(unsigned int time, int action_time);
void			error(char *str);
unsigned int	get_time(void);
int				getter(void *info, int type, pthread_mutex_t *mutex);
void			setter(void *info, int value, pthread_mutex_t *mutex);
void			print(char *s, int id);

/// PARSING 
bool			parse_info(char **av);

// free
void			free_all(void);

// routine
void			start(void);
void			check_stop(t_data *data);

#endif