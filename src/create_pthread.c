/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/20 11:45:21 by ygonzale         ###   ########.fr       */
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
	printf("Filosofo: %d, esta pensando...\n", data->sphilo->philo);
	if (data->sphilo->philo % 2 == 0)
	{
		pthread_mutex_lock(&(data->sphilo->forkright));
		pthread_mutex_lock(&(data->sphilo->forkrleft));
		printf("Filosofo: %d, esta comiendo\n", data->sphilo->philo);
		pthread_mutex_unlock(&(data->sphilo->forkright));
		pthread_mutex_unlock(&(data->sphilo->forkrleft));
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

	aux = (*philo);
	first = (*philo);
	while ((*philo) && (*philo)->next)
	{
		pthread_mutex_init(&(*philo)->forkright, NULL);
		(*philo) = (*philo)->next;
	}
	aux->forkrleft = (*philo)->forkright;
	(*philo) = first;
	while ((*philo) && (*philo)->next)
	{
		(*philo)->next->forkrleft = (*philo)->forkright;
		(*philo) = (*philo)->next;
	}
	(*philo) = first;
	(*philo)->forkrleft = aux->forkrleft;
}
