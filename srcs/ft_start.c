#include "philo.h"

int	ft_start(t_data *data)
{
	int		i;
	t_philo	*philo;
	//pthread_t	p;

	i = 0;
	philo = data->philo;
	
	// if (philo->philo_nb % 2 == 0)
	// 	usleep(1000000);
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
		//puts("che");
	}
	i = 0;
	while (i < data->nb)
	//while (1)
	{
	//printf("i = %d\n", i);
		if (pthread_create(&(philo[i].philo), NULL, ft_routine1, &(philo[i])))
            return (1);
		//printf("i = %d\n", i);
		i++;
	}
	i = 0;
	while (i < data->nb)
    //while (1)
	{    
		pthread_join(philo[i].philo, NULL);
        i++;
	}
	/*
	i = 0;
    while (i < data->philo_nb)
        pthread_mutex_destroy(&(data->fork[i]));
    pthread_mutex_destroy(&(data->write));
	*/
	//ft_exit(data, philo);
	return (0);
}

void	*ft_routine1(void *philo)
{
	int		i;
	t_philo	*philo_cp;
	t_data	*data;

	i = 0;
	philo_cp = (t_philo *)philo;
	if (philo_cp->philo_nb % 2 == 0)
		usleep(1000);
	data = philo_cp->data;
	ft_time_to_eat(philo_cp, data);
	return (NULL);
}
