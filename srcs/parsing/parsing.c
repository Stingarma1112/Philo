/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:54:31 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 20:20:13 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	parsing(t_philo	**philosophers, t_params *params, int argc, char **argv)
{
	if (!init_params(params, argc, argv))
		return (1);
	if (!init_mutexes(params))
	{
		free(params->forks);
		return (1);
	}
	*philosophers = malloc(sizeof(t_philo) * params->nbr_of_philo);
	if (!(*philosophers))
	{
		printf("Error: Memory allocation failed\n");
		free(params->forks);
		return (1);
	}
	if (!init_philosophers(*philosophers, params))
	{
		free(*philosophers);
		free(params->forks);
		return (1);
	}
	return (0);
}
