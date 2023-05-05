/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:31:39 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/20 15:15:34 by ygonzale         ###   ########.fr       */
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
	while (1)
	{
		/* if (data->num_times_eat == -1 && philo->time_have_eaten == data->num_philo)
		{
			printf("num_times_eat: %d\n", data->num_times_eat);
			printf("philo->time_have_eaten: %d\n", philo->time_have_eaten);
			printf("data->num_philo: %d\n", data->num_philo);
			printf("entra en el primero\n");
			break ;
		}
		if (data->num_times_eat != -1 && \
			data->num_times_eat == philo->time_have_eaten)
		{
			printf("entra en el segundo\n");
			break ;
		} */
		if (ft_time(aux->start_time) - aux->sphilo->has_eaten > (long long)aux->time_die)
		{
			pthread_mutex_lock(&(aux->print));
			printf("%lld, %d, died\n", \
				ft_time(aux->start_time), aux->sphilo->philo);
			break ;
		}
		if (aux->sphilo->next)
			aux->sphilo = aux->sphilo->next;
		else
			aux->sphilo = first;
	}
}
