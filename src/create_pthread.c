/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/17 14:49:12 by ygonzale         ###   ########.fr       */
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

void	execute_philosophers(pthread_t thread, t_program *data)
{
	pthread_create(&thread, NULL, worker, (void *)data);
	pthread_join(thread, NULL);
	data->sphilo = data->sphilo->next;
}
