#include "philo.h"

int	ft_init_data(t_data *data, char **av, int ac)
{
	data->count = 1;
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
	data->philo = malloc(sizeof(t_philo) * data->nb);
	if (!data->philo)
		return (1);
	// if (ft_init_philo(data) == 1)
	// 	return (1);
	if (ft_init_mutex(data) == 1)
		return (1);
	//puts ("che");
	ft_init_philo(data);
	return (0);
}

void	ft_init_philo(t_data *data)
{
	int	i;
	t_philo	*philo_cp;	

	i = 0;
	philo_cp = (t_philo *)data;
	//gettimeofday(&data->philo[i].phitime, NULL);
	//printf("nb = %d\n", philo->data->nb);
	while (i < data->nb)
	{
		data->philo[i].philo_nb = i;
		//data->philo[i].phitime = NULL;
		// if (!data->philo[i]) return (1); ?
		if (pthread_create(&data->philo[i].philo, NULL, ft_routine1, &data->philo[i]))
            return ;
		i++;
	}
	i = 0;
	while (1)
	{
		usleep (2000); // a mettre a 200
		ft_routine1(&data->philo[i]);
		if (data->must_eat != 0)
		{
			ft_must_eat(data);
			break;
		}
		i++;
		if (i == data->nb)
			i = 0;
	}
	//while(1); // while != de fin de simulation (fin de si;ul = un philo meurt ou ils ont mange tous leurs repas) > permet 
/*	printf("i = %d\n", i);
	while (1)
	{
		usleep (200);
		//verifier si fin de simul (dans les deux cas : si fin, break)
		ft_time_to_eat(philo_cp, data);
	}
*/	ft_join_thread(data);
	//return (0);
}

void	ft_join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		 pthread_join(data->philo[i].philo, NULL);
		 i++;
	}
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	//printf("nb = %d\n", data->nb);
	while (i < data->nb)
	{
		data->philo[i].left_f = malloc(sizeof(pthread_mutex_t));
		//pthread_mutex_init(&(data->philo->fork_mutex[i]), NULL);
		if (pthread_mutex_init(data->philo[i].left_f, NULL))
		{
			ft_print("Error in mutex\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->nb)
	{
		data->philo[i].right_f = (data->philo[(i + 1) % data->nb].left_f);
		i++;
	}
	return (0);
}
