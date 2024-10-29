/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:16:20 by sabakar-          #+#    #+#             */
/*   Updated: 2024/10/26 01:07:01 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOS 200

typedef struct s_args
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_args;

typedef struct s_philo
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_args			*philos_args;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_is_valid(char **args);
int					ft_is_arg_valid(char **args);
void				ft_init_philo(t_philo *philo, t_args *philos);
void				ft_init_forks(pthread_mutex_t *les_threads, int philo_num);
void				ft_init_args(t_args *philos, t_philo *philo,
						pthread_mutex_t *les_threads, char **av);
size_t				ft_get_current_time(void);
void				ft_create_threads(t_philo *philo,
						pthread_mutex_t *les_forks);
int					ft_usleep(size_t milliseconds);
void				ft_sleep(void);
void				ft_think(void);
void				ft_eat(void);
void     ft_destroy_all(char *message, t_philo *philo, pthread_mutex_t *les_forks);

#endif