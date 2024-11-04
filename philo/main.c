/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:16:32 by sabakar-          #+#    #+#             */
/*   Updated: 2024/10/26 01:09:43 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_is_arg_valid(char **args)
{
	if ((ft_atoi(args[1]) > MAX_PHILOS) || ft_atoi(args[1]) <= 0)
		return (write(2, "Invaild Philosophers number\n", 27), 0);
	if (ft_atoi(args[2]) <= 0)
		return (write(2, "Invalid time to die\n", 21), 0);
	if (ft_atoi(args[3]) <= 0)
		return (write(2, "Invalid time to eat\n", 21), 0);
	if (ft_atoi(args[4]) <= 0)
		return (write(2, "Invalid time to sleep\n", 23), 0);
	if (args[5] && ft_atoi(args[5]) < 0)
		return (write(2, "Invalid number of times each philosopher must eat\n",
				51), 0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_args			args[MAX_PHILOS];
	t_philo			philo;
	pthread_mutex_t	les_forks[MAX_PHILOS];

	if (ac < 5 || ac > 6)
		return (write(2, "You have more than or less of the required args\n", 49), 1);
	if (!ft_is_valid(av))
		return (1);
	if (!ft_is_arg_valid(av))
		return (1);
	ft_init_philo(&philo, args);
	ft_init_forks(les_forks, ft_atoi(av[1]));
	ft_init_args(args, &philo, les_forks, av);
	ft_create_threads(&philo, les_forks);
	ft_destory_all(NULL, &philo, les_forks);
	return (0);
}
