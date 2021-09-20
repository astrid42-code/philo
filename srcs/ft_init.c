/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:35 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/20 16:20:12 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pour les temps : plsrs conversions possibles :
// l'important est de mettre tout au meme niveau (sec? microsec?)
int	ft_init_data(t_data *data, char **av, int ac)
{
	//data->time = 0;
	data->nb = ft_atoi(av[1]) + 1;
	data->die = ft_atoi(av[2]) * 1000;
	data->eat = ft_atoi(av[3]) * 1000;
	data->sleep = ft_atoi(av[4]) * 1000;
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
	gettimeofday(&data->start, NULL);
	// initialiser le(s) t_timeval (au moins le start_eat) pour chaque philo
	// et quand on lance l'action faire le ft_gettime avec le current_time actuel
	// (celui ou en est le dernier philo?) et la valeur du eat/die/sleep...)
	//ft_gettime();
	while (i < data->nb)
	{
		data->philo[i].data = data;
		data->philo[i].philo_nb = i;
		data->philo[i].count = 1;
		data->philo[i].start_eat = data->start;
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

time_t	ft_gettime(t_timeval *current_time, t_timeval *start)
{
	time_t			start;
	struct timeval	timeval;

	gettimeofday(current_time, NULL);
	start = ((current_time->tv_sec * 1000000) + current_time->tv_usec)
		- ((start->tv_sec * 1000000) + start->tv_sec);
	printf("start = %ld\n", start);
	return (start);
}
