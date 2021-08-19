#include "philo.h"

void	*ft_time_to_sleep(void *arg)
{
	(void)arg;
	while (1)
	{
		sleep (1);
		ft_print("Philo is sleeping\n");
	}
	return (NULL);
}

void	ft_time_to_think(void)
{
	while (2)
	{
		sleep (1);
		ft_print("Philo is thinking\n");
	}
}
