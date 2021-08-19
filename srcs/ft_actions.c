#include "philo.h"

void	*ft_time_to_sleep(void *arg)
{
	int	*iptr;
	int i;

	(void)arg;
	iptr = malloc(sizeof(int));
	*iptr = 5;
	i = 0;
	while (*iptr > i)
	{
		sleep (1);
		ft_print("Philo is sleeping\n");
	printf("i = %d\n", i);
		i++;
	}
	free (iptr);
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
