#include "philo.h"

int	ft_start(t_data *data)
{
	int			i;
	//pthread_t	p;

	i = 0;
	if (data->turn == 0)
	{
		while (i < data->nb)
		{
			//if (i % 2 == 0)
			//	ft_routine1(data);
			data->philo->philo_nb++;
		}
		data->turn++;
	}
	//ft_routine2();
	return (0);
}
/*
void	ft_routine1(t_data *data)
{
	//pthread_mutex_t	mutex;
	pthread_t		newthread;

	(void)data;
	pthread_mutex_init(&data->philo.fork_mutex, NULL);
	pthread_create(&newthread, NULL, ft_time_to_eat, (void *)&mutex);
	pthread_join(newthread, NULL);
}
*/