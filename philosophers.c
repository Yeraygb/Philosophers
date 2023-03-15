/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:06:16 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/14 15:14:05 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	get_arguments(t_program *program, char **argv)
{
	int	i;

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

void	*worker(void *arg)
{
	int		count;
	t_philo	*data;

	count = 0;
	data = (t_philo *) arg;
	pthread_mutex_lock(&(data->mute));
	count++;
	printf("Conteo actual: %d\n", count);
	pthread_mutex_unlock(&(data->mute));
	return (NULL);
}

t_philo	*create_philoshoper(t_program *program, t_philo **philo)
{
	t_philo	*philosophers;
	t_philo	*aux;
	int		i;

	i = 0;
	aux = *philo;
	philosophers = (t_philo *) malloc(sizeof(t_philo) * program->num_philo);
	if (!philosophers)
		return (0);
	while (program->num_philo > i)
	{
		pthread_create(&(*philo)->thread[i], NULL, worker, (void *)philo);
		i++;
	}
	return (philosophers);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_program		program;

	if (argc != 5)
		return (0);
	if (get_arguments(&program, argv) == 0)
		return (0);
	pthread_mutex_init(&philo->mute, NULL);
	philo->thread = (pthread_t *) malloc(sizeof(pthread_t) * program.num_philo);
	philo = create_philoshoper(&program, &philo);
	if (!philo->thread == 0)
		return (0);
	return (0);
}
