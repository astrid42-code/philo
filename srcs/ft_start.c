/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:28 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/19 16:26:22 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// part en infini mais bloque quand ils prennent tous leur fourchette gche
// dc pb de mutex de merde > resolu avec 1er philo = 1 et non 0 (!!!)
// autre pb : les philos impairs mangent plein de fois d'affilee au debut > resolu avec reduction du usleep
// nouveau pb : si je mets la data->must_eat : segfault automatique (avec ou sans arg[5]) : resolu (init data dans chaue philo!!!)
void	*ft_routine(void *philo)
{
	int		i;
	t_philo	*philo_cp;
	t_data	*data;

	i = 0;
	philo_cp = (t_philo *)philo;
	data = philo_cp->data;
	if (philo_cp->philo_nb % 2 == 0)
		usleep(100);
	while (1)
	{
		ft_time_to_eat(philo_cp, data);
		if (data->must_eat != 0)
		{
			if (philo_cp->count == data->must_eat)
				break ;
			philo_cp->count++;
		}
		//if (philo died) // ou else if?
			//break;
	}
	return (NULL);
}
