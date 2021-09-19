/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:41:11 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/19 15:41:12 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char**av)
{
	t_data	data;
	int		i;

	if (!(ac == 5 || ac == 6))
	{
		ft_print("Error : wrong number of arguments\n");
		return (1);
	}
	if (ft_init_data(&data, av, ac) == 1)
	{
		ft_free(&data);
		ft_print("Error init\n");
		return (1);
	}
	return (0);
}
