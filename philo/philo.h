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
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
int					ft_create_threads(t_philo *philo,
						pthread_mutex_t *les_forks);
int					ft_usleep(size_t milliseconds);
void				ft_sleep(t_args *philos_args);
void				ft_think(t_args *philos_args);
void				ft_eat(t_args *philos_args);
void				ft_destory_all(char *msg, t_philo *philo,
						pthread_mutex_t *les_forks);
void				*ft_monitor(void *philo_ptr);
void				ft_print_mesg(char *msg, t_args *philos_args, int philo_id);
int					ft_dead_loop(t_args *philo_args);
size_t				ft_strlen(char *sr);

#endif