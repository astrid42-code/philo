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
	data->philo = malloc(sizeof(t_philo*) * data->nb);
	if (!data->philo)
		return (1);
	if (ft_init_philo(data) == 1)
		return (1);
	if (ft_init_mutex(data) == 1)
		return (1);
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int i;

	i = 0;
	//printf("nb = %d\n", philo->data->nb);
	while (i < data->nb)
	{
		data->philo[i].philo_nb = i;
		// if (!data->philo[i]) return (1); ?
		/*if (i % 2 != 0)
			data->philo[i].fork = 1;
		else
			data->philo[i].fork = 0;*/
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->nb;
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	printf("nb = %d\n", data->nb);
	while (i < data->nb)
	{
		//pthread_mutex_init(&(data->philo->fork_mutex[i]), NULL);
		if (pthread_mutex_init(&(data->philo->fork_mutex[i]), NULL))
		{
			ft_print("Error in mutex\n");
			return (1);
		}
		i++;
	}
	//if (pthread_mutex_init(&(data->philo.write), NULL))
    //	return (1);
    //if (pthread_mutex_init(&(rules->meal_check), NULL))
    //  return (1);
	return (0);
}