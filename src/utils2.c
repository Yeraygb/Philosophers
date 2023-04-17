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

/* int	mysleep(t_program data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (data.time_die > time)
		usleep(2 * data.num_philo);
	return (0);
} */

int	ft_msleep(long milisecons, int num_philos)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	while (milisecons > ft_time(timer))
		usleep(2 * num_philos);
	return (0);
}

int	check_eats(t_philo philo, t_program data)
{
	while (1)
	{
		if (data.num_times_eat == -1 && philo.time_have_eaten == data.num_philo)
			return (1);
		if (data.num_times_eat > -1 && \
			data.num_times_eat == philo.time_have_eaten)
			return (1);
		return (0);
	}
}
