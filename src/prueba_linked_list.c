/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:03 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/24 13:56:17 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_philo	*philo_node(int i)
{
	t_philo	*aux;

	aux = ft_calloc(1, sizeof(t_philo));
	if (!aux)
		return (0);
	aux->philo = i + 1;
	aux->next = 0;
	pthread_mutex_init(&(aux->forkright), NULL);
	return (aux);
}

void	add_philo_node(t_philo **philo, t_philo *new_node)
{
	t_philo	*aux;

	if (!*philo)
	{
		*philo = new_node;
		return ;
	}
	aux = *philo;
	while (aux && aux->next)
		aux = aux->next;
	aux->next = new_node;
}

void	init_philo(t_philo **philo, int num_philos)
{
	int		i;
	t_philo	*lastnode;

	i = 0;
	while (i < num_philos)
	{
		add_philo_node(philo, create_philo_node(i));
		i++;
	}
	lastnode = *philo;
	while (lastnode->next)
		lastnode = lastnode->next;
	i = 0;
	while (i < num_philos)
	{
		if (i == num_philos - 1)
			lastnode->forkleft = (*philo)->forkright;
		else
			lastnode->forkleft = lastnode->forkright;
		lastnode = lastnode->next;
		i++;
	}
}

void	create_list(t_philo **philo, int num_philos, int i)
{
	if (i == 0)
	{
		*philo = philo_node(i);
		i++;
	}
	while (num_philos > i)
	{
		add_philo_node(philo, philo_node(i));
		i++;
	}
	init_philo(philo, num_philos);
}
