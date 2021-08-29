#include "philo.h"

// rajouter mutex pour prot2ger les sorties
void	*ft_time_to_sleep(void *mutex)
{
	int	*iptr;
	int	i;

	iptr = malloc(sizeof(int));
	*iptr = 15;
	i = 0;
	while (*iptr > i)
	{
		pthread_mutex_lock(mutex);
		ft_print("Philo is sleeping\n");
		printf("i = %d\n", i);
		pthread_mutex_unlock(mutex);
		usleep (100000);
		i++;
	}
	free (iptr);
	return (NULL);
}

void	*ft_time_to_think(void *mutex)
{
	int	*jptr;
	int	j;

	jptr = malloc(sizeof(int));
	*jptr = 10;
	j = 0;
	while (*jptr > j)
	{
		pthread_mutex_lock(mutex);
		ft_print("Philo is thinking\n");
		printf("j = %d\n", j);
		pthread_mutex_unlock(mutex);
		usleep (100000);
		j++;
	}
	free (jptr);
	return (NULL);
}

void	*ft_time_to_eat(void *mutex)
{
	int	*zptr;
	int	z;

	zptr = malloc(sizeof(int));
	*zptr = 10;
	z = 0;
	while (*zptr > z)
	{
		pthread_mutex_lock(mutex);
		ft_print("Philo is thinking\n");
		printf("j = %d\n", z);
		pthread_mutex_unlock(mutex);
		usleep (100000);
		z++;
	}
	free (zptr);
	return (NULL);
}
