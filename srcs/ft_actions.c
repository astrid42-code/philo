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
/*
void	*ft_time_to_eat(t_philo *philo, t_data *data)
{
	(void)data;
	pthread_mutex_lock(&(philo->fork_mutex[philo->l_fork]));
	ft_print_action(philo, "takes left fork");
	pthread_mutex_lock(&(philo->fork_mutex[philo->r_fork]));
	ft_print_action(philo, "takes right fork");
	ft_print_action(philo, "is eating");
	pthread_mutex_unlock(&(philo->fork_mutex[philo->l_fork]));
	pthread_mutex_unlock(&(philo->fork_mutex[philo->r_fork]));
	return (NULL);
}
*/

void	*ft_time_to_eat(t_philo *philo, t_data *data)
{
	//puts ("che");
	(void)data;
	pthread_mutex_lock(philo->left_f);
	ft_print_action(philo, "has taken a (left) fork");
	pthread_mutex_lock(philo->right_f);
	ft_print_action(philo, "has taken a (right) fork");
	ft_print_action(philo, "is eating");
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	usleep(100);
/*
	if (philo->data->nb % 2 == 1)
	{
		pthread_mutex_lock(philo->left_f);
		ft_print_action(philo, "has taken a (left) fork");
		pthread_mutex_lock(philo->right_f);
		ft_print_action(philo, "has taken a (right) fork");
		ft_print_action(philo, "is eating");
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
	}
	else
	{
		pthread_mutex_lock(philo->right_f);
		ft_print_action(philo, "has taken a (right) fork");
		pthread_mutex_lock(philo->left_f);
		ft_print_action(philo, "has taken a (left) fork");
		ft_print_action(philo, "is eating");
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
	}
*/	return (NULL);
}
