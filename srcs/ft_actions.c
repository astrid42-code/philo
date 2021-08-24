#include "philo.h"

// rajouter mutex pour prot2ger les sorties
void	*ft_time_to_sleep(void *arg)
{
	pthread_mutex_t *mutex;
	int	*iptr;
	int i;

	mutex = arg;
	iptr = malloc(sizeof(int));
	*iptr = 5;
	i = 0;
	while (*iptr > i)
	{
		pthread_mutex_lock(mutex);
		ft_print("Philo is sleeping\n");
		//printf("i = %d\n", i);
		pthread_mutex_unlock(mutex);
		usleep (100000);
		i++;
	}
	free (iptr);
	return (NULL);
}

void	*ft_time_to_think(void *arg)
{
	pthread_mutex_t *mutex;
	int	*jptr;
	int j;

	mutex = arg;
	jptr = malloc(sizeof(int));
	*jptr = 10;
	j = 0;
	while (*jptr > j)
	{
		pthread_mutex_lock(mutex);
		ft_print("Philo is thinking\n");
		//printf("j = %d\n", j);
		pthread_mutex_unlock(mutex);
		usleep (100000);
		j++;
	}
	free (jptr);
	return (NULL);
}
