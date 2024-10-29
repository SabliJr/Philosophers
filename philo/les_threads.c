/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   les_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 10:59:51 by sabakar-          #+#    #+#             */
/*   Updated: 2024-10-28 10:59:51 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int		ft_dead_loop(t_args *philo_args);
void	*ft_philo_routine(void *philo_ptr);

void	ft_create_threads(t_philo *philo, pthread_mutex_t *les_forks)
{
	int	z;

	z = -1;
	while (++z < philo->philos_args->num_of_philos)
	{
		if (pthread_create(&philo[z].philos_args->thread, NULL,
				&ft_philo_routine, &philo->philos_args[z]) != 0)
			ft_destroy_all("There was an err creating thread!", philo,
				les_forks);
	}
	while (++z < philo->philos_args->num_of_philos)
	{
		if (pthread_join(philo[z].philos_args->thread, NULL) != 0)
			ft_destroy_all("Thre was an err joining threads!", philo,
				les_forks);
	}
}

void	*ft_philo_routine(void *philo_ptr)
{
	t_args	*philo_args;

	philo_args = (t_args *)philo_ptr;
	if (philo_args->id % 2 == 0)
		ft_usleep(1);
	while (!ft_dead_loop(philo_args))
	{
		ft_eat();
		ft_sleep();
		ft_think();
	}
	return (philo_args);
}

int	ft_dead_loop(t_args *philo_args)
{
	pthread_mutex_lock(philo_args->dead_lock);
	if (*philo_args->dead == 1)
		return (pthread_mutex_unlock(philo_args->dead_lock), 1);
	pthread_mutex_unlock(philo_args->dead_lock);
	return (0);
}