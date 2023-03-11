#include "include/philosophers.h"

int get_argv(t_program *program, char **argv)
{
	int i;
	
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	pthread_mutex_init(&program->print, NULL);
	pthread_mutex_init(&program->eat, NULL);
	pthread_mutex_init(&program->dead, NULL);
	pthread_mutex_init(&program->sleep, NULL);
	program->num_philo = ft_atoi(argv[1]);
	program->time_die = ft_atoi(argv[2]);
	program->time_eat = ft_atoi(argv[3]);
	program->time_sleep = ft_atoi(argv[4]);
	return (1);
}

/* int create_philo(t_program *program, t_philo philo)
{
	program->num_philo = 
	return (1);
} */

t_philo	*create_philoshoper(t_program *program)
{
	int i;
	t_philo *philosophers;

	i = 0;
	philosophers = (t_philo *) malloc(sizeof(t_philo) * program->num_philo);
	if (!philosophers)
		return (0);
	while (program->num_philo > i)
	{
		//
		i++;
	}
	return (philosophers);
}


int main(int argc, char **argv)
{
	t_program	program;
	t_philo		*philo;

	if (argc != 5)
		return (0);
	if (get_argv(&program, argv) == 0)
		return (0);
	philo.thread = (pthread_t*) malloc(sizeof(pthread_t) * program.num_philo);
	philo = create_philoshoper(&program)
	/* if (create_philoshoper(&program));
		return (0); */
	return (0);
}
