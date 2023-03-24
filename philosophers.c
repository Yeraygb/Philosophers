/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:06:16 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/24 13:33:25 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"
#include <sys/time.h>

int	get_arguments(t_program *data, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->sleep, NULL);
	pthread_mutex_init(&data->mute, NULL);
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_times_eat = ft_atoi(argv[5]);
	else
		data->num_times_eat = -1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_program		data;

	if (argc < 4 || argc > 5)
		return (0);
	if (get_arguments(&data, argv) == 0)
		return (0);
	gettimeofday(&data.start_time, NULL);
	data.thread = (pthread_t *) malloc(sizeof(pthread_t) * data.num_philo);
	if (!data.thread)
		return (0);
	philo = create_philoshoper(&data);
	//init_forks(&philo);
	/* while (philo)
	{
		printf("%d\n", philo->philo);
		philo = philo->next;
	} */
	data.sphilo = philo;
	execute_philosophers(&data);
	exit_program(&data, &philo);
	free(philo);
	return (0);
}
