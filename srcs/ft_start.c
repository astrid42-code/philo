#include "philo.h"
/*
int	ft_start(t_data *data)
{
	int		i;
	//pthread_t	p;

	i = 0;
	philo = data->philo;
	// if (philo->philo_nb % 2 == 0)
	// 	usleep(1000000);
	if (data->turn == 0)
	{
		while (i < data->nb)
		{
	//printf("i = %d\n", i);
			if (i % 2 != 0)
			{
				if (pthread_create(&(philo[i].philo), NULL, ft_routine1, &(philo[i])))
            		return (1);
			}
			i++;
		}
		data->turn++;
	}
	i = 0;
	while (i < data->nb)
    //while (1)
	{    
		pthread_join(philo[i].philo, NULL);
        i++;
		if (i == data->nb)
			i = 0;
	}
	i = 0;
    while (i < data->philo_nb)
        pthread_mutex_destroy(&(data->fork[i]));
    pthread_mutex_destroy(&(data->write));
	//ft_exit(data, philo);
	return (0);
}*/

void	*ft_routine1(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	//puts("che");
	philo = data->philo;
	while (1)
	{
		ft_time_to_eat(philo, data);
		usleep(200);
	}
	return (NULL);
}
