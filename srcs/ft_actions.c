/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:43 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/21 11:44:23 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_time_to_sleep(t_philo *philo, t_data *data)
{
	ft_print_action(philo, data, "is sleeping");
	return (NULL);
}

void	*ft_time_to_think(t_philo *philo, t_data *data)
{
	ft_print_action(philo, data, "is thinking");
	return (NULL);
}

void	*ft_time_to_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_f);
	ft_print_action(philo, data, "has taken a (left) fork");
	pthread_mutex_lock(philo->right_f);
	ft_print_action(philo, data, "has taken a (right) fork");
	ft_print_action(philo, data, "is eating");
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	usleep(100);
	return (NULL);
}
