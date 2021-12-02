/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:50 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 11:37:19 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data->philo;
	ft_join_thread(data);
	if (data->must_eat != 0)
		ft_print("count reached\n", 0);
	else if (data->philo->life == 1)
		ft_print_action(philo, data, "died");
	while (i < data->nb)
	{
		pthread_mutex_destroy(data->philo[i].left_f);
		i++;
	}
	pthread_mutex_destroy(data->write);
}

void	ft_join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		pthread_join(data->philo[i].philo_thread, NULL);
		i++;
	}
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		free(data->philo);
		i++;
	}
}
