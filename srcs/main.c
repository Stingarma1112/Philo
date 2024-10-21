/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:22:40 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 18:51:58 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_params	params;

	if (!init_params(&params, argc, argv))
		return (1);
	if (!init_mutexes(&params))
	{
		free(params.forks);
		return (1);
	}
	return (0);
}
