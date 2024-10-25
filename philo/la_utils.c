/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:58:52 by sabakar-          #+#    #+#             */
/*   Updated: 2024/10/25 22:54:14 by sabakar-         ###   ########.fr       */
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

int is_valid(char **args)
{
    int x;

     x = 0;
    while (args[++x])
    {
        if (!ft_is_digit(args[x]))
        {
            write(2, "Invalid input!", 15);
            return (0);
        }
    }

    return (1);
}