/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:16:32 by sabakar-          #+#    #+#             */
/*   Updated: 2024/10/25 23:25:38 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int main (int ac, char *av[])
{
    int x;
    
    if (ac < 5 || ac > 6)
        return (printf("You have more than or less of the required args\n"), 1);

    if (!is_valid(av))
        return (1);
    
    x = 1;
    while (x < ac)
    {
        printf("The args: [%d]\n", ft_atoi(av[x]));
        x++;
    }

    return (0);
}
