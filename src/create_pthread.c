/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/12 13:52:09 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/* void	check_philo_die(t_program *data, t_philo *philo)
{
	data->num_eated = 0;
	while (1)
	{
		if (data->time_die > ft_time(data->start_time))
		{
			pthread_mutex_lock(&(data->print));
			printf("%lld, %d is dead\n", ft_time(data->start_time), philo->philo);
			break ;
		}
		else if (data->num_eated >= data->num_times_eat)
			break ;
	}
} */

void	process_eating(t_program *data)
{
	pthread_mutex_lock(&(data->print));
	pthread_mutex_lock(&data->sphilo->forkleft);
	printf("%lld, %d, has taken a fork\n", \
		ft_time(data->start_time), data->sphilo->philo);
	pthread_mutex_unlock(&(data->print));
	pthread_mutex_lock(&data->sphilo->forkright);
	pthread_mutex_lock(&(data->print));
	printf("%lld, %d, has taken a fork\n", \
		ft_time(data->start_time), data->sphilo->philo);
	pthread_mutex_unlock(&(data->print));
	pthread_mutex_lock(&(data->print));
	printf("%lld, %d, is eating\n", \
		ft_time(data->start_time), data->sphilo->philo);
	data->sphilo->time_have_eaten++;
	pthread_mutex_unlock(&(data->print));
	pthread_mutex_unlock(&data->sphilo->forkright);
	pthread_mutex_unlock(&data->sphilo->forkleft);
}


void	*worker(void *arg)
{
	t_program	*data;
	t_philo		*philo;

	data = (t_program *) arg;
	philo = data->sphilo;
	pthread_mutex_unlock(&(data->print));
	pthread_mutex_lock(&(data->mute));
	data->sphilo->time_eat = ft_time(data->start_time) + data->time_die;
	pthread_mutex_unlock(&(data->mute));
	if (data->sphilo->philo % 2)
		ft_msleep(data->time_eat -20, data->num_philo);
	while (1)
	{
		process_eating(data);
		pthread_mutex_lock(&(data->print));
		printf("%lld, %d, is sleeping\n", \
			ft_time(data->start_time), data->sphilo->philo);
		pthread_mutex_unlock(&(data->print));
		ft_msleep(data->time_sleep, data->num_philo);
		pthread_mutex_lock(&(data->print));
		printf("%lld, %d, is thinking\n", \
			ft_time(data->start_time), data->sphilo->philo);
		pthread_mutex_unlock(&(data->print));
	}
	return (NULL);
}

void	execute_philosophers(t_program *data)
{
	int		i;
	t_philo	*first;

	first = data->sphilo;
	i = 0;
	pthread_mutex_lock(&data->mute);
	while (data->num_philo > i)
	{
		pthread_mutex_lock(&(data->print));
		pthread_create(&data->thread[i], NULL, worker, (void *)data);
		pthread_detach(data->thread[i]);
		pthread_mutex_lock(&(data->print));
		i++;
		data->sphilo = data->sphilo->next;
		pthread_mutex_unlock(&(data->print));
	}
	pthread_mutex_unlock(&(data->mute));
	pthread_mutex_unlock(&(data->print));
	data->sphilo = first;
}
