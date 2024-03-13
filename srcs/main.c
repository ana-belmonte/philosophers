/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:18:09 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/12 17:45:22 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*dinner(void)
{
	static t_data	dinner;

	return (&dinner);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!parse_info(av))
			printf("Wrong values"); 
		//init_data(); // fazer 
		//start_prog(); // fazer
	}
	else
	{
		printf("Wrong number of arguments");
		return (1);
	}
	return (0);
}
