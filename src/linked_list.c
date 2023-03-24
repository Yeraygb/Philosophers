/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:42:14 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/24 14:00:57 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/* void	create_list(t_philo **philo, int bol, int i)
{
	t_philo	*first;
	t_philo	*aux;

	first = (*philo);
	aux = ft_calloc(1, sizeof(t_philo));
	if (!aux)
		return ;
	aux->philo = i + 1;
	aux->next = 0;
	if (bol == 0)
	{
		(*philo)->philo = aux->philo;
		(*philo)->next = 0;
		free(aux);
		bol++;
	}
	else
	{
		while ((*philo) && (*philo)->next)
			(*philo) = (*philo)->next;
		(*philo)->next = aux;
	}
	(*philo) = first;
}

t_philo	*create_philoshoper(t_program *data)
{
	int		i;
	int		boleana;
	t_philo	*philo;

	i = 0;
	boleana = 0;
	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (0);
	while (data->num_philo > i)
	{
		if (boleana == 0)
		{
			create_list(&philo, boleana, i);
			boleana++;
			i++;
		}
		else
		{
			create_list(&philo, boleana, i);
			i++;
		}
	}
	return (philo);
}

void	init_forks(t_philo **philo)
{
	t_philo	*firstnode;
	t_philo	*lastnode;

	firstnode = (*philo);
	while ((*philo) && (*philo)->next)
	{
		pthread_mutex_init(&(*philo)->forkright, NULL);
		(*philo) = (*philo)->next;
	}
	lastnode = (*philo);
	(*philo) = firstnode;
	while ((*philo) && (*philo)->next)
	{
		(*philo)->next->forkleft = (*philo)->forkright;
		(*philo) = (*philo)->next;
	}
	(*philo) = firstnode;
	(*philo)->forkleft = lastnode->forkleft;
}
 */

void ini_forks()
{

}

void	create_list(t_philo **philo, int bol, int i)
{
	t_philo	*firstnode;
	t_philo	*aux;
	t_philo	*lastnode;

	firstnode = (*philo);
	aux = ft_calloc(1, sizeof(t_philo));
	if (!aux)
		return ;
	aux->philo = i + 1;
	aux->next = 0;
	pthread_mutex_init(&(aux->forkright), NULL);
	if (bol == 0)
	{
		(*philo)->philo = aux->philo;
		(*philo)->next = 0;
		free(aux);
		bol++;
	}
	else
	{
		while ((*philo) && (*philo)->next)
			(*philo) = (*philo)->next;
		(*philo)->next = aux;
	}
	(*philo) = firstnode;
	if (bol == i)
	{
		lastnode = aux;
		while ((*philo) && (*philo)->next)
		{
			(*philo)->next->forkleft = (*philo)->forkright;
			(*philo) = (*philo)->next;
		}
		(*philo) = firstnode;
		(*philo)->forkleft = lastnode->forkright;
	}
}

t_philo	*create_philoshoper(t_program *data)
{
	int		i;
	int		boleana;
	t_philo	*philo;

	i = 0;
	boleana = 0;
	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (0);
	while (data->num_philo > i)
	{
		create_list(&philo, boleana, i);
		boleana++;
		i++;
	}
	return (philo);
}
