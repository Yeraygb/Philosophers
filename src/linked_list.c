/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:42:14 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/15 12:43:22 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*worker(void *arg)
{
	int			count;
	t_program	*data;

	count = 0;
	data = (t_philo *) arg;
	pthread_mutex_lock(&(data->mute));
	count++;
	printf("Conteo actual: %d\n", count);
	pthread_mutex_unlock(&(data->mute));
	return (NULL);
}

void	create_list(t_program *data, t_philo **philo, int bol, pthread_t thread)
{
	t_philo	*first;
	t_philo	*aux;

	first = philo;
	aux = ft_calloc(1, sizeof(t_philo));
	aux->philo = pthread_create(thread, NULL, worker, (void *)data);
	aux->next = 0;
	if (bol == 0)
	{
		(*philo)->philo = aux->philo;
		(*philo)->next = 0;
		bol++;
	}
	else
	{
		while ((*philo) && (*philo)->next)
			(*philo) = (*philo)->next;
		(*philo)->next = aux;
	}
	philo = aux;
}

void	create_philoshoper(t_program *data, t_philo **philo)
{
	int		i;
	int		boleana;

	i = 0;
	boleana = 0;
	while (data->num_philo > i)
	{
		if (boleana == 0)
		{
			create_list(data, philo, boleana, data->thread[i]);
			boleana++;
			i++;
		}
		else
		{
			create_list(data, philo, boleana, data->thread[i]);
			i++;
		}
		i++;
	}
}
