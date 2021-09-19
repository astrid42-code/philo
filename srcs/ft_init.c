/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:35 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/19 16:40:44 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(t_data *data, char **av, int ac)
{
	data->nb = ft_atoi(av[1]) + 1;
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	if (ft_check_arg(ac, av, data) == 1)
	{
		// fct pour free l struct (si malloc)
		return (1);
	}
	data->philo = malloc(sizeof(t_philo) * data->nb);
	if (!data->philo)
		return (1);
	if (ft_init_mutex(data) == 1)
		return (1);
	if (ft_init_philo(data) == 1)
		return (1);
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 1;
	gettimeofday(&data->philo[i].phitime, NULL);
	//printf("nb = %d\n", philo->data->nb);
	while (i < data->nb)
	{
		data->philo[i].data = data;
		data->philo[i].philo_nb = i;
		data->philo[i].count = 1;
		//data->philo[i].phitime = NULL; > comment initialiser cette variable?
		// if (!data->philo[i]) return (1); ?
		if (pthread_create(&data->philo[i].philo_thread, NULL, ft_routine, &data->philo[i]))
            return (1);
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->philo[i].left_f = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(data->philo[i].left_f, NULL))
		{
			ft_print("Error in mutex\n");
			return (1);
		}
		i++;
	}
	ft_init_mutex_rfork(data);
	data->write = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->write, NULL))
	{
		ft_print("Error in mutex\n");
		return (1);
	}
	return (0);
}

void	ft_init_mutex_rfork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->philo[i].right_f = (data->philo[(i + 1) % data->nb].left_f);
		i++;
	}
}
