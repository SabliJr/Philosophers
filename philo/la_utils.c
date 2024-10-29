/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:58:52 by sabakar-          #+#    #+#             */
/*   Updated: 2024/10/26 00:48:30 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_check_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_digit(char *sr)
{
	int x;

	x = -1;
	while (sr[++x])
	{
		if (!ft_check_num(sr[x]))
			return (0);
	}

	return (1);
}

int ft_is_valid(char **args)
{
    int x;

     x = 0;
    while (args[++x])
    {
        if (!ft_is_digit(args[x]))
        {
            write(2, "Invalid input!\n", 15);
            return (0);
        }
    }

    return (1);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}