#include "philo.h"

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
	else
		philo->must_eat = 0;
	return (*philo);
}

int	main(int ac, char **av)
{
	t_philo			philo;
	//int				*result;
	//pthread_t		newthread;
	//pthread_mutex_t	mutex;

	//pthread_mutex_init(&mutex, NULL);
	if (!(ac == 5 || ac == 6))
	{
		ft_print("Error : wrong number of arguments\n");
		return (1);
	}
	philo = ft_init(&philo, av, ac);
	//if (ft_init)
	if (ft_check_arg(ac, av, &philo) == 1)
	{
		// fct pour free l struct (si malloc)
		return (1);
	}
	//printf("%d %d %d %d %d %d\n", philo.fork, philo.philo, philo.die, philo.eat, philo.sleep, philo.must_eat);
	// pthread_create(&newthread, NULL, ft_time_to_sleep, (void *)&mutex);
	// pthread_create(&newthread, NULL, ft_time_to_think, (void *)&mutex);
	// //result = malloc(sizeof(int));
	// //*result = 5;
	// pthread_join(newthread, (void *)&result);
	// pthread_join(newthread, (void *)&result);

	return (0);
}
