/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 13:05:35 by sabakar-          #+#    #+#             */
/*   Updated: 2024-10-29 13:05:35 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int		ft_is_philo_dead(t_args *philo_args, size_t p_time_to_die);
int		ft_is_all_ate(t_args *philo_args);
int		ft_is_dead(t_args *philo_args);

void	*ft_monitor(void *philo_ptr)
{
	t_args	*philo_args;

	philo_args = (t_args *)philo_ptr;
	while (1)
		if (ft_is_dead(philo_args) || ft_is_all_ate(philo_args))
			break ;
	return (philo_ptr);
}

int	ft_is_dead(t_args *philo_args)
{
	int	o;

	o = 0;
	while (o < philo_args[0].num_of_philos)
	{
		if (ft_is_philo_dead(&philo_args[o], philo_args[o].time_to_die))
		{
			ft_print_mesg("died", &philo_args[o], philo_args[o].id);
			pthread_mutex_lock(philo_args[0].dead_lock);
			*philo_args->dead = 1;
			pthread_mutex_unlock(philo_args[0].dead_lock);
			return (1);
		}
		o++;
	}
	return (0);
}

int	ft_is_all_ate(t_args *philo_args)
{
	int	x;
	int	k;
	int	finished_eating;

	x = 0;
	finished_eating = 0;
	if (philo_args->num_times_to_eat == -1)
		return (0);
	while (x < philo_args[0].num_of_philos)
	{
		pthread_mutex_lock(philo_args[x].meal_lock);
		if (philo_args[x].meals_eaten >= philo_args[x].num_times_to_eat)
		{
			// printf("The philo finished eating:-> %d\n", philo_args[x].id);
			finished_eating++;
		}
		pthread_mutex_unlock(philo_args[x].meal_lock);
		x++;
	}
	k = finished_eating * philo_args[0].num_times_to_eat;
	if (finished_eating == philo_args[0].num_of_philos
		&& ((!(philo_args[0].num_times_to_eat < 0))
			&& (k == philo_args[0].num_of_philos
				* philo_args[0].num_times_to_eat)))
	{
		printf("All the philos finished eating\n");
		pthread_mutex_lock(philo_args[0].dead_lock);
		*philo_args->dead = 1;
		pthread_mutex_unlock(philo_args[0].dead_lock);
		return (1);
	}
	// if (finished_eating == philo_args[0].num_of_philos)
	// {
	// 	printf("The K is -> %d\n", k);
	// 	pthread_mutex_lock(philo_args[0].dead_lock);
	// 	*philo_args->dead = 1;
	// 	pthread_mutex_unlock(philo_args[0].dead_lock);
	// 	return (1);
	// }
	return (0);
}

int	ft_is_philo_dead(t_args *philo_args, size_t p_time_to_die)
{
	pthread_mutex_lock(philo_args->meal_lock);
	if (ft_get_current_time() - philo_args->last_meal >= p_time_to_die
		&& philo_args->eating == 0)
		return (pthread_mutex_unlock(philo_args->meal_lock), 1);
	pthread_mutex_unlock(philo_args->meal_lock);
	return (0);
}
