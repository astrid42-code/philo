#include "philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	//int				*result;
	//pthread_t		newthread;
	// pthread_t		newthread1;
	// pthread_t		newthread2;
	// pthread_t		newthread3;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	if (!(ac == 5 || ac == 6))
	{
		ft_print("Error : wrong number of arguments\n");
		return (1);
	}
	//philo = ft_init(&philo, av, ac);
	ft_init(&data, av, ac);
	//if (!ft_init)
	// msg erreur + return (1)
	
	//printf("%d %d %d %d %d %d\n", philo.fork, philo.philo, philo.die, philo.eat, philo.sleep, philo.must_eat);
	// pthread_create(&newthread, NULL, ft_time_to_sleep, (void *)&mutex);
	// pthread_create(&newthread, NULL, ft_time_to_think, (void *)&mutex);
	// pthread_create(&newthread, NULL, ft_time_to_eat, (void *)&mutex);
	//result = malloc(sizeof(int));
	//*result = 5;
	//  pthread_join(newthread, (void *)&result);
	//  pthread_join(newthread, (void *)&result);
	//  pthread_join(newthread, (void *)&result);
	pthread_join(newthread, NULL);
	// pthread_join(newthread, NULL);
	// pthread_join(newthread, NULL);
	//free(result);
	return (0);
}
