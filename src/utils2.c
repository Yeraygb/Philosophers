/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:31:39 by ygonzale          #+#    #+#             */
/*   Updated: 2023/05/20 11:28:33 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <sys/time.h>

int	mysleep(int time_state, t_program *data)
{
	long long	time;

	(void)data;
	time = ft_time(data->start_time);
	while (time_state > ft_time(data->start_time) - time)
	{
		usleep(250);
		usleep(250);
		usleep(250);
		usleep(250);
	}
	return (0);
}

void	check_states(t_program *data)
{
	t_program	*aux;
	t_philo		*first;

	first = data->sphilo;
	aux = data;
	data->eat = 0;
	while (1)
	{
		if (ft_time(aux->start_time) - aux->sphilo->has_eaten > \
			(long long)aux->time_die)
		{
			pthread_mutex_lock(&(aux->print));
			printf("%lld, %d, died\n", \
				ft_time(aux->start_time), aux->sphilo->philo);
			break ;
		}
		check_eats(data, aux);
		if (data->eat == data->num_philo)
			break ;
		if (aux->sphilo->next)
			aux->sphilo = aux->sphilo->next;
		else
			aux->sphilo = first;
	}
}

void	check_eats(t_program *data, t_program *aux)
{
	if (data->num_times_eat > -1 && \
			(aux->sphilo->time_have_eaten == data->num_times_eat + 1))
			data->eat++;
}
