/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:08:40 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/20 13:05:03 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <sys/time.h>


void exit_program(t_program *data, t_philo **philo)
{
	t_philo	*aux;

	free(data->thread);
	while ((*philo))
	{
		aux = (*philo);
		(*philo) = (*philo)->next;
		free(aux);
	}
	//free((*philo));
	//exit(0);
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
	time = (actual_time.tv_sec * 1000) + (actual_time.tv_usec / 1000) - (starttime.tv_sec * 1000) + (starttime.tv_usec / 1000);
	return (time);
}
