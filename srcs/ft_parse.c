#include "philo.h"

int	ft_check_data(t_philo *philo)
{
	if (philo->philo <= 1)
	{
		ft_print("Error : there is no philosopher here!\n");
		return (1);
	}
	else if (philo->philo > 200)
	{
		ft_print("Error : there are too many philosophers here!\n");
		return (1);
	}
	else if (philo->die < 60 || philo->eat < 60 || philo->sleep < 60)
	{
		ft_print("Error : wrong parameters\n");
		return (1);
	}
	return (0);
}

int	ft_check_arg(int ac, char **av, t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				ft_print("Error in arguments\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_check_data(philo) == 1)
		return (1);
	return (0);
}
