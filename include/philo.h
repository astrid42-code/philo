#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int				philo_nb; // id du philo
	int				count;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_t		philo_thread;
	t_timeval		current_time;
	t_timeval		start_eat;
	struct timeval	start_think;
	struct timeval	start_sleep;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nb; // nbr total de philos
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	t_timeval		start;
	pthread_mutex_t	*write;
	t_philo			*philo;
}				t_data;

int		main(int ac, char **av);
int		ft_check_arg(int ac, char **av, t_data *data);
int		ft_check_data(t_data *data);
int		ft_start(t_data *data);
void	*ft_routine(void *philo);
void	*ft_time_to_sleep(void *arg);
void	*ft_time_to_think(void *arg);
void	*ft_time_to_eat(t_philo *philo, t_data *data);
void	ft_must_eat(t_data *data);

// init / exit
int		ft_init_philo(t_data *data);
int		ft_init_data(t_data *data, char **av, int ac);
int		ft_init_mutex(t_data *data);
void	ft_init_mutex_rfork(t_data *data);
time_t	ft_gettime(t_timeval *current_time, t_timeval *start);
void	ft_exit(t_data *data);
void	ft_join_thread(t_data *data);

// utils
void	ft_print(char *str);
void	ft_print_action(t_philo *philo, t_data *data, char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_free(t_data *data);
int		ft_nbrsize(int nbr);

#endif