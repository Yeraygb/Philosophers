#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>

typedef struct s_philo
{
	int philo;
	pthread_t	*thread;
	struct s_list *right_philo;
	struct s_list *left_philo;
	
}	t_philo;

typedef struct s_program
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int 			time_sleep;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	sleep;
	pthread_mutex_t	print;
}	t_program;


int		get_argv(t_program *program, char **argv);
void	exit_program(t_philo list, int numexit);
t_philo	*create_philoshoper(t_program *program);
int		ft_atoi(const char *str);


#endif