/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:18:09 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/20 16:29:58 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_data	*dinner(void)
{
	static t_data	dinner;

	return (&dinner);
}

// void print_struct(t_data *data)
// {
// 	printf("eat_time : %ld\n", data->eat_time);
// 	printf("die_time : %ld\n", data->die_time);
// 	printf("sleep_time : %ld\n", data->sleep_time);
// 	printf("n philos : %d\n", data->n_philos);
// 	printf("n eats: %d\n", data->n_eats);
// 	printf("cur_time : %d\n", data->cur_time);
// 	printf("finish: %d\n", data->finish);
// 	printf("philo id: %d\n", data->philos[3].id);
// 	printf("left id: %d\n", data->philos[3].left->id);
// 	printf("right id: %d\n", data->philos[3].right->id);
// }

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!parse_info(av))
		{
			error("Wrong arguments format");
			return(1);
		}
		if(!init_data(av))
			return(1);
		//print_struct(dinner());
		
		start(); 
	}
	else
	{
		error("Wrong number of arguments");
		return (1);
	}
	return (0);
}
