/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:35 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 12:07:45 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pour les temps : plsrs conversions possibles :
// l'important est de mettre tout au meme niveau (sec? microsec?)
int	ft_init_data(t_data *data, char **av, int ac)
{
	memset(data, 0, sizeof(t_data));
	data->nb = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	if (ft_check_arg(ac, av, data) == 1)
		return (1);
	// data->philo = malloc(sizeof(t_philo) * data->nb);
	// memset(data->philo, 0, sizeof(t_philo) * data->nb);
	// if (!data->philo)
	// 	return (1);
	// if (ft_init_mutex(data) == 1)
	// 	return (1);
	// if (ft_init_philo(data) == 1)
	// 	return (1);
	return (0);
}
/*
int	ft_init_philo(t_data *data)
{
	int	i;

	i = 1;
	gettimeofday(&data->start_time, NULL);
	// initialiser le(s) t_timeval (au moins le start_eat) pour chaque philo
	// et quand on lance l'action faire le ft_gettime avec le current_time actuel
	// (celui ou en est le dernier philo?) et la valeur du eat/die/sleep...)
	//data->philo[i].start_eat = ft_gettime(&data->start_time,  &data->philo[i].start_eat);
	while (i < data->nb)
	{
		data->philo[i].data = data;
		data->philo[i].philo_nb = i;
		data->philo[i].count = 1;
		//data->start_time = data->start_time;
		//data->philo[i].current_time = data->start;
		//data->philo[i].last_eat = ft_gettime(&data->start_time, &data->philo[i].start_eat);
		// recuperer dans un unsigned long plutot que dqns start eat.tv_sec
		// if (!data->philo[i]) return (1); ?
		if (pthread_create(&data->philo[i].philo_thread, NULL, ft_routine, &data->philo[i]))
            return (1);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < data->philo[i].philo_nb)
		{
			if (data->philo[i].life == 1)
				ft_exit(data);
			i++;
			if (i == data->philo->philo_nb)
				i = 0;
		}
	}

	//boucler sur les philos en mettant la condition :
	// si philo[i]->last_eat - data->start_time (tempps actuel - dernier repas) (ou plutot le dernier en cours du philo) > timetodie alors life == 1
	return (0);
}

// pt de depart : timestamp (ie current)
// a chaque fois qu ils mangent tu recuperes le timestamp
// ensuite tu soustrais le start_time (on ne le touche jms) du last_eat

// si le last_eat - start_time est > au time_to_die alos le philo est mort
// dans ce cas variable life = 1 (au lieu de 0) et dire aux philos que si life == 1 > ca s arrete (ft_exit)
int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->philo[i].left_f = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(data->philo[i].left_f, NULL))
			return (ft_print("Error in mutex\n", 1));
		i++;
	}
	ft_init_mutex_rfork(data);
	data->write = malloc(sizeof(pthread_mutex_t));
	data->dead = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->write, NULL)
		|| pthread_mutex_init(data->dead, NULL))
		return (ft_print("Error in mutex\n", 1));
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

unsigned long	ft_gettime(t_timeval *start_time, t_timeval *start_eat)
{
	unsigned long	time;

	//printf("start_time = %ld %d\n start_eat = %ld %d\n", start_time->tv_sec, start_time->tv_usec, start_eat->tv_sec, start_eat->tv_usec);
	time = (unsigned long)(((start_eat->tv_sec * 1000)
				+ (start_eat->tv_usec * 0.001))
			- ((start_time->tv_sec * 1000) + (start_time->tv_usec * 0.001)));
	//printf("time = %ld\n", time);
	return (time);
}
*/