#include "philo.h"

int	ft_init_data(t_data *data, char **av, int ac)
{
	//t_philo philo;
	//int i;

	data->turn = 0;
	data->nb = ft_atoi(av[1]);
	//printf("nb = %d\n", data->nb);
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
	ft_init_philo(data);
	return (0);
}

//t_data	*ft_init_philo(t_data *data, int i)
void	ft_init_philo(t_data *data)
{
	int i;

	i = 0;
	//printf("nb = %d\n", philo->data->nb);
	while (i < data->nb)
	{
		data->philo[i].philo_nb = i;
		if (i % 2 != 0)
			data->philo[i].fork = 1;
		else
			data->philo[i].fork = 0;
		//data->philo[i].l_fork = i;
		//data->philo[i].r_fork = (i + 1) % data->nb;
		i++;
	}
	//return (data);
}
