/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:06:23 by ygonzale          #+#    #+#             */
/*   Updated: 2023/03/14 15:12:16 by ygonzale         ###   ########.fr       */
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
	pthread_t		*thread;
	pthread_mutex_t	mute;

}	t_philo;

typedef struct s_program
{
	int				num_philo; // Numero de filosofos (1º argumento)
	int				time_die;
	int				time_eat;
	int				time_sleep;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	sleep;
	pthread_mutex_t	print;
}	t_program;

//---------- LIBFT ----------//

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

//---------- PHILOSOPHERS ----------//

int		get_arguments(t_program *program, char **argv);
//void	exit_program(t_philo list, int numexit);
t_philo	*create_philoshoper(t_program *program, t_philo **philo);

#endif