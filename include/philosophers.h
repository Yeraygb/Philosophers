/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:06:23 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/15 15:14:23 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_philo
{
	int				philo;
	int				eat;
	struct s_philo	*next;
}	t_philo;

typedef struct s_program
{
	int				num_philo; // Numero de filosofos (1º argumento)
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_times_eat;
	pthread_t		*thread;
	pthread_mutex_t	mute;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	sleep;
}	t_program;

//---------- LIBFT ----------//

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

//---------- PHILOSOPHERS ----------//

int		get_arguments(t_program *data, char **argv);
void	create_philoshoper(t_program *data, t_philo **philo);
void	create_list(t_program *data, t_philo *philo, int bol, pthread_t thread);
//void	exit_program(t_philo list, int numexit);

#endif