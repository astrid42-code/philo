#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	// int			l_fork;
	// int			r_fork;
	// pthread_t	philo_nb;
	int				philo_nb; // id du philo
	int				fork;
	//int				l_fork;
	//int				r_fork;
	//pthread_mutex_t	fork_mutex;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int			turn;
	int			nb; // nbr total de philos
	int			die;
	int			eat;
	int			sleep;
	int			must_eat;
	t_philo		*philo;
}				t_data;

int		main(int ac, char **av);
int		ft_check_arg(int ac, char **av, t_data *data);
int		ft_check_data(t_data *data);
void	ft_init_philo(t_data *data);
int		ft_init_data(t_data *data, char **av, int ac);
void	*ft_time_to_sleep(void *arg);
void	*ft_time_to_think(void *arg);
void	*ft_time_to_eat(void *mutex);

// utils
void	ft_print(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_free(t_data *data);

#endif