/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:20:10 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 01:00:30 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	validate_params(t_params *params)
{
	
}

int	init_params(t_params *params, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage : %s nbr_of_philo tdie teat tsleep [meals_required]\n", argv[0]);
		return (0);
	}
	params->nbr_of_philo = ft_atoi(argv[1]);
}