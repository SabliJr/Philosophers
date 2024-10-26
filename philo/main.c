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

int is_arg_valid(char **args, int ac)
{
    if ((ft_atoi(args[1]) > MAX_PHILOS) || ft_atoi(args[1]))
        return ("Invaild Philosophers number\n", 0);
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
	int		x;
	t_args	args[MAX_PHILOS];
	t_philo	philo;
    pthread_mutex_t les_threads[MAX_PHILOS];

	if (ac < 5 || ac > 6)
		return (printf("You have more than or less of the required args\n"), 1);
        
	if (!is_valid(av))
		return (1);
        
	if (!is_arg_valid(av))
		return (1);
        
	init_philo(&philo, args);
    init_threads(les_threads, ft_atoi(av[1]));
	init_args(args, philo, les_threads, av);
    
	return (0);
}