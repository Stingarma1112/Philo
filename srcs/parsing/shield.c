/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:46:21 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 20:17:52 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_ressources(t_philo *philosophers, t_params *params, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&params->forks[i]);
		i++;
	}
	if (count == params->nbr_of_philo)
		pthread_mutex_destroy(&params->print_mutex);
	free(philosophers);
	free(params->forks);
}
