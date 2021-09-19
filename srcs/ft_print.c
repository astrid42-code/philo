#include "philo.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_action(t_philo *philo, t_data *data, char *str)
{
/*	int	*i;

	i = &philo->philo_nb;
	printf("i = %d\n", *i);
	write(1, "philo ", 6);
	write(1, &i, ft_nbrsize(*i));
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
*/	
	(void)data;
	// puts("che");
	// pthread_mutex_lock(data->write);
	 printf("philo %d %s\n", philo->philo_nb, str);
	// pthread_mutex_unlock(data->write);
}
