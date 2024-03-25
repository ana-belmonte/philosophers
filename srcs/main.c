/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:18:09 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/25 20:07:12 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
		{
			error("Wrong arguments format");
			return(1);
		}
		if(!init_data(av))
			return(1);
		start(); 
	}
	else
	{
		error("Wrong number of arguments");
		return (1);
	}
	return (0);
}
