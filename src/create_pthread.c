/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/20 13:35:34 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/* void	philo_eating(t_program data)
{
	
} */

void	*worker(void *arg)
{
	t_program	*data;

	data = (t_program *) arg;
	printf("%lld, %d, is thinking...\n", \
	ft_time(data->start_time), data->sphilo->philo);
	pthread_mutex_lock(&(data->sphilo->forkright));
	pthread_mutex_lock(&(data->sphilo->forkleft));
	printf("%lld, %d, is eating\n", \
	ft_time(data->start_time), data->sphilo->philo);
	pthread_mutex_unlock(&(data->sphilo->forkleft));
	pthread_mutex_unlock(&(data->sphilo->forkright));
/* 	while (1)
	{
	}
	if (pthread_mutex_lock(&(data->sphilo->forkrleft)) == 0)
	{
	} */
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
		pthread_join(data->thread[i], NULL);
		i++;
		data->sphilo = data->sphilo->next;
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
	//aux->forkrleft = (*philo)->forkright;
	(*philo) = first;
	while ((*philo) && (*philo)->next)
	{
		(*philo)->next->forkleft = (*philo)->forkright;
		(*philo) = (*philo)->next;
	}
	(*philo) = first;
	(*philo)->forkleft = aux->forkleft;
}
