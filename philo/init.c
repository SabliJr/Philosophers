/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:56:39 by sabakar-          #+#    #+#             */
/*   Updated: 2024/10/26 01:15:05 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void    init_philo(t_philo *philo, t_args *philos)
{
    philo->dead_flag = 0;
    philo->philos_args = philos;
    thread_mutex_init(philo->dead_lock, NULL);
    thread_mutex_init(philo->meal_lock, NULL);
    thread_mutex_init(philo->write_lock, NULL);
}

void    init_input(t_args *args, char **av)
{
    args->num_of_philos = av[1];
    args->time_to_die = av[2];
    args->time_to_eat = av[3];
    args->time_to_sleep = av[4];
    if (av[5])
        args->num_times_to_eat = av[5];
    else
        args->num_times_to_eat = -1;
}

void    init_threads(pthread_mutex_t *les_threads, int philo_num)
{
    int k;

    k = -1;
    while (++k < philo_num)
        pthread_mutex_init(&les_threads[k], NULL);
}

void    init_args(t_args *args, t_philo *philo, pthread_mutex_t *les_threads, char **av)
{
    int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		args[i].id = i + 1;
		args[i].eating = 0;
		args[i].meals_eaten = 0;
		init_input(&args[i], av);
		args[i].start_time = get_current_time();
		args[i].last_meal = get_current_time();
		args[i].write_lock = &philo->write_lock;
		args[i].dead_lock = &philo->dead_lock;
		args[i].meal_lock = &philo->meal_lock;
		args[i].dead = &philo->dead_flag;
		args[i].l_fork = &les_threads[i];
		if (i == 0)
			args[i].r_fork = &les_threads[args[i].num_of_philos - 1];
		else
			args[i].r_fork = &les_threads[i - 1];
	}
}