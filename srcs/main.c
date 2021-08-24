#include "philo.h"

int	ft_check_arg(int ac, char **av, t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				ft_print("Error in arguments\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (philo->philo <= 1)
	{
		ft_print("Error : there is no philosopher here!\n");
		return (1);
	}
	return (0);
}

t_philo	ft_init(t_philo *philo, char **av, int ac)
{
	philo->philo_nb = 0;
	philo->fork = ft_atoi(av[1]);
	philo->philo = ft_atoi(av[1]);
	philo->die = ft_atoi(av[2]);
	philo->eat = ft_atoi(av[3]);
	philo->sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->must_eat = ft_atoi(av[5]);
	return (*philo);
}

int	main(int ac, char **av)
{
	int			*result;
	t_philo		philo;
	pthread_t	newthread;
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	if (!(ac == 5 || ac == 6))
	{
		//if (ac == 6)
		// verifier l'arg pour cette option avec un strcmp?
		ft_print("Error : wrong number of arguments\n");
		return (1);
	}
	philo = ft_init(&philo, av, ac);
	if (ft_check_arg(ac, av, &philo) == 1)
		return (1);
	//printf("%d %d %d %d %d %d\n", philo.fork, philo.philo, philo.die, philo.eat, philo.sleep, philo.must_eat);
	pthread_create(&newthread, NULL, ft_time_to_sleep, (void *)&mutex);
	pthread_create(&newthread, NULL, ft_time_to_think, (void *)&mutex);
	// result = malloc(sizeof(int));
	// *result = 5;
	pthread_join(newthread, (void *)&result);
	pthread_join(newthread, (void *)&result);
	return (0);
}
