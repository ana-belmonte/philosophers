/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:55:09 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/27 14:55:12 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	check_stop(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < data->n_philos)
		{
			if ((int)get_time() 
				- getter(&data->philos[i].lst_eaten, 2, &dinner()->glb) 
				>= getter(&data->die_time, 2, &dinner()->glb) 
				|| getter(&data->philos[i].n_eats, 1, &dinner()->glb)
				>= getter(&data->n_eats, 1, &dinner()->glb))
			{
				setter(&dinner()->finish, 1, &dinner()->glb);
				print("has died", data->philos[i].id);
				return ;
			}
			usleep(100);
		}
	}
}
