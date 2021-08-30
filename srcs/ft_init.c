#include "philo.h"

int	ft_init_data(t_data *data, char **av, int ac)
{
	data->turn = 0;
	data->nb = ft_atoi(av[1]);
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
	return (0);
}

int	ft_init_philo(t_philo *philo)
{
	philo->philo_nb = 0;
	philo->fork = 0;
	return (0);
}
