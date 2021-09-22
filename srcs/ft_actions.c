/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:43 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/22 16:28:48 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_time_to_sleep(t_philo *philo, t_data *data)
{
	ft_print_action(philo, data, "is sleeping");
	// data->last_eat += ft_gettime(&data->start_time, &data->start_eat)
	// 	+ data->sleep;
	usleep(100);
	return (NULL);
}

void	*ft_time_to_think(t_philo *philo, t_data *data)
{
	ft_print_action(philo, data, "is thinking");
	return (NULL);
}

void	*ft_time_to_eat(t_philo *philo, t_data *data)
{
	gettimeofday(&philo->philo_start_eat, NULL);
	pthread_mutex_lock(philo->left_f);
	ft_print_action(philo, data, "has taken a (left) fork");
	pthread_mutex_lock(philo->right_f);
	ft_print_action(philo, data, "has taken a (right) fork");
	gettimeofday(&philo->philo_start_eat, NULL);
	//printf("start = %ld %ld\n", &philo->start_eat.tv_sec, &philo->start_eat.tv_usec);
	//philo->last_eat = ft_gettime(&data->start_time, &philo->start_eat) + data->eat;
	ft_print_action(philo, data, "is eating");
	//printf("last_eat = %ld\n",data->last_eat);
	//data->last_eat = ft_gettime(&data->start_time, &philo->philo_start_eat);
	ft_usleep(data, philo);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	usleep(100);
	return (NULL);
}

void	ft_usleep(t_data *data, t_philo *philo)
{	
	unsigned long	time;

	gettimeofday(&data->start_eat, NULL);
	time = ft_gettime(&data->start_time, &philo->philo_start_eat);
	while (time < (unsigned long)data->eat)
		usleep(500);
}
