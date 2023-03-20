/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:06:16 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/15 15:07:05 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

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
	t_philo		*philo;
	t_program	data;

	if (argc < 4 || argc > 5)
		return (0);
	if (get_arguments(&data, argv) == 0)
		return (0);
	data.thread = (pthread_t *) malloc(sizeof(pthread_t) * data.num_philo);
	if (!data.thread)
		return (0);
	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (0);
	create_philoshoper(&data, &philo);
	init_forks(&philo);
	data.sphilo = philo;
	execute_philosophers(&data);
/* 	while (philo && philo->next)
	{
		printf("filosofos: %d\n", philo->philo);
		philo = philo->next;
	} */
	return (0);
}