#include "philo.h"

int	ft_start(t_data *data)
{
	int		i;
	t_philo	*philo;
	//pthread_t	p;

	i = 0;
	philo = data->philo;
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
	{
	//printf("i = %d\n", i);
		if (pthread_create(&(philo[i].philo), NULL, ft_routine1, &(philo[i])))
            return (1);
		i++;
	}
	//ft_exit(data, philo);
	return (0);
}

void	*ft_routine1(void *philo)
{
	int		i;
	t_philo	*philo_cp;
	t_data	*data;

	i = 0;
	//puts("che");
	philo_cp = (t_philo *)philo;
	data = philo_cp->data;
	ft_time_to_eat(philo_cp, data);
	return (NULL);
}
