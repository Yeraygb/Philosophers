/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:08:40 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/20 14:42:22 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <sys/time.h>

void	free_philos(t_philo *philo, t_program *data)
{
	t_philo	*tmp;

	free(data->thread);
	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		pthread_mutex_destroy(&tmp->forkright);
		free(tmp);
	}
	pthread_mutex_destroy(&data->mute);
	pthread_mutex_destroy(&data->print);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	c = (void *)malloc(count * size);
	if (!c)
		return (NULL);
	ft_bzero(c, count * size);
	return (c);
}

/*---------------------------------------------------------------------------
* Funcion para convertir un char en int

* @param {const char *str} el fichero que tiene que leer

* @return {int}
---------------------------------------------------------------------------*/

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sig;

	i = 0;
	num = 0;
	sig = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sig * num);
}

long long	ft_time(struct timeval starttime)
{
	long long		time;
	struct timeval	actual_time;

	gettimeofday(&actual_time, NULL);
/* 	time = (actual_time.tv_sec * 1000) + (actual_time.tv_usec / 1000) \
	- (starttime.tv_sec * 1000) + (starttime.tv_usec / 1000); */
	time = (((actual_time.tv_sec - starttime.tv_sec) * 1000) \
		+ (actual_time.tv_usec - starttime.tv_usec) / 1000);
	return (time);
}
