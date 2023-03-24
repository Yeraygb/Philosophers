/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/23 12:38:15 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*worker(void *arg)
{
	t_program	*data;

	data = (t_program *) arg;
	while (1)
	{
		printf("%lld, %d, is thinking...\n", \
		ft_time(data->start_time), data->sphilo->philo);
		sleep(rand() % 5);
		pthread_mutex_lock(&(data->mute));
		pthread_mutex_lock(&(data->sphilo->forkright));
		printf("%lld, %d, ha cogido el tenedor derecho\n", \
		ft_time(data->start_time), data->sphilo->philo);
		pthread_mutex_lock(&(data->sphilo->forkleft));
		printf("%lld, %d, ha cogido el tenedor izq\n", \
		ft_time(data->start_time), data->sphilo->philo);
		pthread_mutex_unlock(&(data->mute));
		printf("%lld, %d, is eating\n", \
		ft_time(data->start_time), data->sphilo->philo);
		sleep(rand() % 5);
		pthread_mutex_unlock(&(data->sphilo->forkleft));
		printf("%lld, %d, ha liberado el tenedor derecho\n", \
		ft_time(data->start_time), data->sphilo->philo);
		pthread_mutex_unlock(&(data->sphilo->forkright));
	}
	return (NULL);
}

void	execute_philosophers(t_program *data)
{
	int		i;
	t_philo	*first;

	first = data->sphilo;
	i = 0;
	while (data->num_philo > i)
	{
		pthread_create(&data->thread[i], NULL, worker, (void *)data);
		i++;
		data->sphilo = data->sphilo->next;
	}
	i = 0;
	while (data->num_philo > i)
	{
		pthread_detach(data->thread[i]);
		i++;
	}
	data->sphilo = first;
}

void	init_forks(t_philo **philo)
{
	t_philo	*first;
	t_philo	*aux;

	first = (*philo);
	while ((*philo) && (*philo)->next)
	{
		pthread_mutex_init(&(*philo)->forkright, NULL);
		(*philo) = (*philo)->next;
	}
	aux = (*philo);
	(*philo) = first;
	while ((*philo) && (*philo)->next)
	{
		(*philo)->next->forkleft = (*philo)->forkright;
		(*philo) = (*philo)->next;
	}
	(*philo) = first;
	(*philo)->forkleft = aux->forkleft;
}
