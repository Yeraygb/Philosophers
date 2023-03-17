/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:42:14 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/17 12:32:27 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	create_list(t_philo *philo, int bol, int i)
{
	t_philo	*first;
	t_philo	*aux;

	first = philo;
	aux = ft_calloc(1, sizeof(t_philo));
	aux->philo = i + 1;
	aux->next = 0;
	if (bol == 0)
	{
		philo->philo = aux->philo;
		philo->next = 0;
		bol++;
	}
	else
	{
		while (philo && philo->next)
			philo = philo->next;
		philo->next = aux;
	}
	philo = first;
}

void	create_philoshoper(t_program *data, t_philo **philo)
{
	int		i;
	int		boleana;

	i = 0;
	boleana = 0;
	while (data->num_philo >= i)
	{
		if (boleana == 0)
		{
			create_list(*philo, boleana, i);
			boleana++;
			i++;
		}
		else
		{
			create_list(*philo, boleana, i);
			i++;
		}
	}
}
