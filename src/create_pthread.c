/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/31 11:49:17 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
	}
	// while (1)
	// {
	// 	printf("%lld, %d, is thinking...\n", \
	// 	ft_time(data->start_time), data->sphilo->philo);
	// 	sleep(rand() % 5);
	// 	pthread_mutex_lock(&(data->sphilo->forkright));
	// 	pthread_mutex_lock(&(data->sphilo->forkleft));
	// 	printf("%lld, %d, is eating\n", \
	// 	ft_time(data->start_time), data->sphilo->philo);
	// 	sleep(rand() % 5);
	// 	pthread_mutex_unlock(&(data->sphilo->forkleft));
	// 	pthread_mutex_unlock(&(data->sphilo->forkright));
	// }
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
		pthread_mutex_lock(&(data->mute));
		pthread_create(&data->thread[i], NULL, worker, (void *)data);
		pthread_detach(data->thread[i]);
		i++;
		data->sphilo = data->sphilo->next;
	}
	pthread_mutex_unlock(&(data->print));
	data->sphilo = first;
}
