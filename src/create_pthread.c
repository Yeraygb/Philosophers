/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/04 13:23:05 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	process_eating(t_program *data)
{
	pthread_mutex_lock(&(data->print));
	printf("%lld, %d, is eating\n", \
		ft_time(data->start_time), data->sphilo->philo);
	pthread_mutex_unlock(&(data->print));
}

void	*worker(void *arg)
{
	t_program	*data;
	t_philo		*philo;

	data = (t_program *) arg;
	philo = data->sphilo;
	pthread_mutex_unlock(&(data->mute));
	pthread_mutex_lock(&(data->print));
	printf("%d\n", philo->philo);
	pthread_mutex_unlock(&(data->print));
	while (1)
	{
	/* 	pthread_mutex_lock(&(data->print));
		printf("%lld, %d, is thinking...\n", \
		ft_time(data->start_time), data->sphilo->philo);
		pthread_mutex_unlock(&(data->print)); 
		process_eating(&data); */
	}
	return (NULL);
}

void	execute_philosophers(t_program *data)
{
	int		i;
	t_philo	*first;

	first = data->sphilo;
	i = 0;
	pthread_mutex_lock(&(data->print));
	while (data->num_philo > i)
	{
		pthread_mutex_lock(&(data->print));
		pthread_create(&data->thread[i], NULL, worker, (void *)data);
		pthread_detach(data->thread[i]);
		pthread_mutex_unlock(&(data->print));
		i++;
		data->sphilo = data->sphilo->next;
	}
	pthread_mutex_unlock(&(data->print));
	data->sphilo = first;
}

void	check_philo_die(t_program *data, t_philo *philo)
{
	data->num_eated = 0;
	while (1)
	{
		if (data->time_die > ft_time(data->start_time))
		{
			pthread_mutex_lock(&(data->print));
			printf("%lld, %d is dead\n", ft_time(data->start_time), philo->philo);
			break ;
		}
		else if (data->num_eated >= data->num_times_eat)
			break ;
	}
}
