#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_philo
{
	int fork;
	int philo;
	int die;
	int eat;
	int sleep;
	int must_eat;
}				t_philo;


int		main (int ac, char **av);
void	ft_error(char *str);
t_philo	ft_init(t_philo *philo, char **av, int ac);

// utils
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif