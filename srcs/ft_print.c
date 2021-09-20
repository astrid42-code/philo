/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:19 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/20 20:41:52 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_action(t_philo *philo, t_data *data, char *str)
{
	(void)data;
	pthread_mutex_lock(data->write);
	printf("%ld ", philo->start_eat.tv_sec);
	 printf("philo %d %s\n", philo->philo_nb, str);
	pthread_mutex_unlock(data->write);
}
