#include "philo.h"

t_philo	ft_init(t_philo *philo, char **av, int ac)
{
	philo->fork = ft_atoi(av[1]);
	philo->philo = ft_atoi(av[1]);
	philo->die = ft_atoi(av[2]);
	philo->eat = ft_atoi(av[3]);
	philo->sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->must_eat = ft_atoi(av[5]);
	else
		philo->must_eat = 0;
	if (ft_check_arg(ac, av, &philo) == 1)
	{
		// fct pour free l struct (si malloc)
		return ;
	}

	return (*philo);
}
