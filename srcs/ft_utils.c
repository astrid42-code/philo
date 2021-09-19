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
