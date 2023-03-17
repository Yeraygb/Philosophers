/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/17 14:56:36 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*worker(void *arg)
{
	int			count;
	t_program	*data;

	count = 0;
	data = (t_program *) arg;
	pthread_mutex_lock(&(data->mute));
	count++;
	printf("filosofo: %d, esta comiendo\n", data->sphilo->philo);
	//printf("Conteo actual: %d\n", count);
	pthread_mutex_unlock(&(data->mute));
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
}
