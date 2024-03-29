/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:42:14 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/12 13:56:40 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	create_node(t_philo **philo, int i)
{
	t_philo	*aux;
	t_philo	*lastnode;

	aux = ft_calloc(1, sizeof(t_philo));
	if (!aux)
		return ;
	aux->philo = i + 1;
	aux->next = 0;
	aux->time_have_eaten = 0;
	pthread_mutex_init(&(aux->forkright), NULL);
	if ((*philo) == NULL)
	{
		(*philo) = aux;
	}
	else
	{
		lastnode = (*philo);
		while (lastnode->next != NULL)
			lastnode = lastnode->next;
		lastnode->next = aux;
	}
}

void	connect_forks(t_philo *philo)
{
	t_philo	*lastnode;
	t_philo	*firstnode;

	firstnode = philo;
	lastnode = philo;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	while (philo->next != NULL)
	{
		philo->next->forkleft = &philo->forkright;
		philo = philo->next;
	}
	philo = firstnode;
	philo->forkleft = &lastnode->forkright;
}

void	create_list(t_philo **philo, int bol, int i)
{
	create_node(philo, i);
	if (bol == i)
		connect_forks(*philo);
}

t_philo	*create_philoshoper(t_program *data)
{
	int		i;
	int		boleana;
	t_philo	*philo;

	philo = NULL;
	i = 0;
	boleana = 0;
	while (data->num_philo > i)
	{
		create_list(&philo, boleana, i);
		boleana++;
		i++;
	}
	return (philo);
}
