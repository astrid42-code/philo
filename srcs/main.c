/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:41:11 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 12:06:48 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char**av)
{
	t_data	data;

	if (!(ac == 5 || ac == 6))
		return (ft_print("Error : wrong number of arguments\n", 1));
	if (ft_init_data(&data, av, ac) == 1)
	{
		//ft_free(&data); // ou ft_exit?
		return (1);
	}
	//ft_exit(&data);
	return (0);
}
