/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:07 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 10:15:53 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_nbrsize(int nbr)
{
	int	count;
	int	tmp;

	count = 0;
	tmp = nbr;
	if (nbr == 0)
	{
		count++;
		return (count);
	}
	while (nbr > 0)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

int	ft_print(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

void	ft_print_action(t_philo *philo, t_data *data, char *str)
{
	(void)data;
	pthread_mutex_lock(data->write);
	printf("%ld ", data->last_eat);
	printf("philo %d %s\n", philo->philo_nb, str);
	pthread_mutex_unlock(data->write);
}
