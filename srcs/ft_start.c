/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:28 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/21 16:40:39 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// routine de chaque philo (executee dans un thread a part pour chaque philo)
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
		// fct ft_check_death : think puis manger puis dormir puis check si temps entre deux repas ok
		if (ft_check_death(philo_cp, data) == 1)
			break ;
		if (data->must_eat != 0)
		{
			if (philo_cp->count == data->must_eat)
				break ;
			philo_cp->count++;
		}
	}
	return (NULL);
}

int	ft_check_death(t_philo *philo, t_data *data)
{
	ft_time_to_think(philo, data);
	ft_time_to_eat(philo, data);
	ft_time_to_sleep(philo, data); // peuvent ils continuer a dormir apres le dernier repas?
	if (ft_check_eat(philo) == 1)
		return (1);
	return (0);
}

int	ft_check_eat(t_philo *philo)
{
	printf("life = %d\n", philo->life);
	if (philo->life == 1)
		return (1);
	return (0);
}