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

// part en infini mais bloque quand ils prennent tous leur fourchette gche
// dc pb de mutex de merde > resolu avec 1er philo = 1 et non 0 (!!!)
// autre pb : les philos impairs mangent plein de fois d'affilee au debut > resolu avec reduction du usleep
// nouveau pb : si je mets la data->must_eat : segfault automatique (avec ou sans arg[5])
void	*ft_routine1(void *philo)
{
	int		i;
	t_philo	*philo_cp;
	t_data	*data;

	i = 0;
	philo_cp = (t_philo *)philo;
	data = philo_cp->data;
	//printf("m = %d\n", philo_cp->data->must_eat);
	if (philo_cp->philo_nb % 2 == 0)
		usleep(100);
	while (1)
	{
		ft_time_to_eat(philo_cp, data);
/*		printf("m = %d\n", data->must_eat);
		// data->count : a mettre en fait dans les philos? des qu'un philo mange, son compteur augmente jusqu a arriver a la limite definie?
		if (data->must_eat != 0)
		{
			printf("count = %d\n", data->count);
			if (data->count == data->must_eat)
				break;
			data->count++;
		}
*/	
	}
	//ft_time_to_eat(philo_cp, data);
	return (NULL);
}
