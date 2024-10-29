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

void    ft_eat()
{

}

void    ft_sleep()
{

}

void ft_think () 
{

}

void     ft_destroy_all(char *message, t_philo *philo, pthread_mutex_t *les_forks)
{
    (void)philo;
    (void)les_forks;

    printf("The msg: %s\n", message);
}