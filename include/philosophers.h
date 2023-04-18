/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:06:23 by ygonzale          #+#    #+#             */
/*   Updated: 2023/04/12 13:18:20 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//-------------- INCLUDES --------------//

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//-------------- STRUCTS --------------//

typedef struct s_philo
{
	int				philo;
	int				eat;
	long long		time_eat;
	int				time_have_eaten;
	pthread_mutex_t	forkright;
	pthread_mutex_t	forkleft;
	struct s_philo	*next;
}	t_philo;

typedef struct s_program
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_times_eat;
	int				num_eated;
	long long		s_time;
	struct timeval	start_time;
	t_philo			*sphilo;
	pthread_t		*thread;
	pthread_mutex_t	mute;
	pthread_mutex_t	print;
}	t_program;

//-------------- UTILS --------------//

int			get_arguments(t_program *data, char **argv);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
long long	ft_time(struct timeval startime);
void		free_philos(t_philo *philo, t_program *data);

//---------- CREATE LINKED LIST -----------//

t_philo		*create_philoshoper(t_program *data);
void		create_list(t_philo **philo, int bol, int i);
void		create_node(t_philo **philo, int i);
void		connect_forks(t_philo *philo);

//---------- PTHREAD -----------//

void		execute_philosophers(t_program *data);
void		*worker(void *arg);
void		check_philo_die(t_program *data, t_philo *philo);
int			ft_msleep(long milisecons, int num_philos);
int			mysleep(t_program data)

#endif