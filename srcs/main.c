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
	return (*philo);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	pthread_t	newthread;

	if (!(ac == 5 || ac == 6))
	{
		//if (ac == 6)
		// verifier l'arg pour cette option avec un strcmp?
		ft_print("Error : wrong number of arguments");
		return (1);
	}
	philo = ft_init(&philo, av, ac);
	printf("%d %d %d %d %d %d\n", philo.fork, philo.philo, philo.die, philo.eat, philo.sleep, philo.must_eat);
	pthread_create(&newthread, NULL, ft_time_to_sleep, NULL);
	ft_time_to_think();
	pthread_join(newthread, NULL);
	return (0);
}
