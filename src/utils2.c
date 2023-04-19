/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:31:39 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/17 11:58:44 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <sys/time.h>

int	mysleep(int time_state, t_program *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	while (time_state > ft_time(time))
		usleep(2 * data->num_philo);
	return (0);
}

void	check_states(t_philo *philo, t_program *data)
{
	/* (void) philo;
	(void) data; */
	//printf("entra\n");
	while (1)
	{
		//printf("entra al while\n");
		if (data->num_times_eat == -1 && philo->time_have_eaten == data->num_philo)
		{
			printf("num_times_eat: %d\n", data->num_times_eat);
			printf("philo->time_have_eaten: %d\n", philo->time_have_eaten);
			printf("data->num_philo: %d\n", data->num_philo);
			printf("entra en el primero\n");
			break ;
		}
		if (data->num_times_eat > -1 && \
			data->num_times_eat == philo->time_have_eaten)
		{
			printf("entra en el segundo\n");
			break ;
		}
	}
}
