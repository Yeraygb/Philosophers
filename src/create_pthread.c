/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:27 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/20 13:42:47 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	process_eating(t_program *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->forkleft);
	pthread_mutex_lock(&(data->print));
	printf("%lld, %d, has taken a fork\n", \
		ft_time(data->start_time), philo->philo);
	pthread_mutex_unlock(&(data->print));
	pthread_mutex_lock(&philo->forkright);
	pthread_mutex_lock(&(data->print));
	printf("%lld, %d, has taken a fork\n", \
		ft_time(data->start_time), philo->philo);
	pthread_mutex_unlock(&(data->print));
	pthread_mutex_lock(&(data->print));
	printf("%lld, %d, is eating\n", \
		ft_time(data->start_time), philo->philo);
	philo->time_have_eaten++;
	data->has_eaten = ft_time(data->start_time);
	pthread_mutex_unlock(&(data->print));
	mysleep(data->time_eat, data);
	pthread_mutex_unlock(&philo->forkright);
	pthread_mutex_unlock(&philo->forkleft);
}

void	*worker(void *arg)
{
	t_program	*data;
	t_philo		*philo;

	data = (t_program *) arg;
	philo = data->sphilo;
	pthread_mutex_unlock(&(data->print));
	/* pthread_mutex_lock(&(data->mute));
	philo->time_eat = ft_time(data->start_time) + data->time_die;
	pthread_mutex_unlock(&(data->mute)); */
	if (philo->philo % 2)
		mysleep(60, data);
	while (1)
	{
		process_eating(data, philo);
		pthread_mutex_lock(&(data->print));
		printf("%lld, %d, is sleeping\n", \
			ft_time(data->start_time), philo->philo);
		pthread_mutex_unlock(&(data->print));
		mysleep(data->time_sleep, data);
		pthread_mutex_lock(&(data->print));
		printf("%lld, %d, is thinking\n", \
			ft_time(data->start_time), philo->philo);
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
		pthread_create(&data->thread[i], NULL, worker, data);
		pthread_detach(data->thread[i]);
		pthread_mutex_lock(&(data->print));
		data->sphilo = data->sphilo->next;
		i++;
		pthread_mutex_unlock(&(data->print));
	}
	pthread_mutex_unlock(&(data->mute));
	pthread_mutex_unlock(&(data->print));
	data->sphilo = first;
}
