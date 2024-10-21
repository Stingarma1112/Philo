/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:22:40 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 22:51:54 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philosophers;
	int			i;
	
	if (parsing(&philosophers, &params, argc, argv))
		return (1);
	i = 0;
	while (i < params.nbr_of_philo)
	{
		if (pthread_create(&philosophers[i].thread, NULL, philosopher_routine, &philosophers[i]) != 0)
		{
            printf("Error: Failed to create thread for philosopher %d\n", philosophers[i].id);
            free_ressources(philosophers, &params, params.nbr_of_philo);
            return (1);
        }
		i++;
	}
	i = 0;
    while (i < params.nbr_of_philo)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
	free_ressources(philosophers, &params, params.nbr_of_philo);
	return (0);
}
