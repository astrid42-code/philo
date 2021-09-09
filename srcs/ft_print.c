#include "philo.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_action(t_philo *philo, char *str)
{
	printf("philo %d %s\n", philo->philo_nb, str);
}
