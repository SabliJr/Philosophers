/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 12:35:01 by sabakar-          #+#    #+#             */
/*   Updated: 2024-10-28 12:35:01 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_think(t_args *philos_args)
{
	ft_print_mesg("is Thinking\n", philos_args, philos_args->id);
}

void	ft_sleep(t_args *philos_args)
{
	ft_print_mesg("is Sleeping\n", philos_args, philos_args->id);
	ft_usleep(philos_args->time_to_sleep);
}

void	ft_eat(t_args *philos_args)
{
	pthread_mutex_lock(philos_args->r_fork);
	ft_print_mesg("has taken a fork", philos_args, philos_args->id);
	if (philos_args->num_of_philos == 1)
	{
		ft_usleep(philos_args->time_to_die);
		pthread_mutex_unlock(philos_args->r_fork);
		return ;
	}
	pthread_mutex_lock(philos_args->l_fork);
	ft_print_mesg("has taken a fork", philos_args, philos_args->id);
	philos_args->eating = 1;
	ft_print_mesg("is eating", philos_args, philos_args->id);
	pthread_mutex_lock(philos_args->meal_lock);
	philos_args->last_meal = ft_get_current_time();
	philos_args->meals_eaten++;
	pthread_mutex_unlock(philos_args->meal_lock);
	ft_usleep(philos_args->time_to_eat);
	philos_args->eating = 0;
	pthread_mutex_unlock(philos_args->l_fork);
	pthread_mutex_unlock(philos_args->r_fork);
}

void	ft_destory_all(char *msg, t_philo *philo, pthread_mutex_t *les_forks)
{
	int	k;

	k = 0;
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 2);
	}
	pthread_mutex_destroy(&philo->dead_lock);
	pthread_mutex_destroy(&philo->meal_lock);
	pthread_mutex_destroy(&philo->write_lock);
	while (k < philo->philos_args[0].num_of_philos)
	{
		pthread_mutex_destroy(&les_forks[k]);
		k++;
	}
}

size_t	ft_strlen(char *sr)
{
	size_t	x;

	x = 0;
	while (sr[x])
		x++;
	return (x);
}
