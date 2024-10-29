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

void	ft_init_philo(t_philo *philo, t_args *philos)
{
	philo->dead_flag = 0;
	philo->philos_args = philos;
	pthread_mutex_init(&philo->meal_lock, NULL);
	pthread_mutex_init(&philo->dead_lock, NULL);
	pthread_mutex_init(&philo->write_lock, NULL);
}

void	ft_init_input(t_args *args, char **av)
{
	args->num_of_philos = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->num_times_to_eat = ft_atoi(av[5]);
	else
		args->num_times_to_eat = -1;
}

void	ft_init_forks(pthread_mutex_t *les_forks, int philo_num)
{
	int	k;
	int	x;

	k = -1;
	x = 0;
	while (++k < philo_num)
	{
		pthread_mutex_init(&les_forks[k], NULL);
		x++;
	}
}

void	ft_init_args(t_args *args, t_philo *philo, pthread_mutex_t *les_forks,
		char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		args[i].id = i + 1;
		args[i].eating = 0;
		args[i].meals_eaten = 0;
		ft_init_input(&args[i], av);
		args[i].start_time = ft_get_current_time();
		args[i].last_meal = ft_get_current_time();
		args[i].write_lock = &philo->write_lock;
		args[i].dead_lock = &philo->dead_lock;
		args[i].meal_lock = &philo->meal_lock;
		args[i].dead = &philo->dead_flag;
		args[i].l_fork = &les_forks[i];
		if (i == 0)
			args[i].r_fork = &les_forks[args[i].num_of_philos - 1];
		else
			args[i].r_fork = &les_forks[i - 1];
	}
}
