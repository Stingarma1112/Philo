/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:05 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/22 01:22:53 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philosopher_think(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (philosopher->params->sim_run)
	{
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		pthread_mutex_lock(&philosopher->params->print_mutex);
		printf("Philo %d is thinking...\n", philosopher->id);
		pthread_mutex_unlock(&philosopher->params->print_mutex);
	}
	else
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
}

void	philosopher_eat(t_philo *philosopher)
{
	if (philosopher->id % 2 == 0)
    {
        pthread_mutex_lock(philosopher->left_fork);
        pthread_mutex_lock(philosopher->right_fork);
    }
    else
    {
        pthread_mutex_lock(philosopher->right_fork);
        pthread_mutex_lock(philosopher->left_fork);
    }
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (philosopher->params->sim_run)
	{
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		pthread_mutex_lock(&philosopher->params->print_mutex);
		printf("Philo %d is eating...\n", philosopher->id);
		pthread_mutex_unlock(&philosopher->params->print_mutex);	
		philosopher->last_meal_time = get_time();
		ft_usleep(philosopher->params->time_to_eat);
	}
	else
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	philosopher_sleep(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (philosopher->params->sim_run)
	{
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		pthread_mutex_lock(&philosopher->params->print_mutex);
		printf("Philo %d is sleeping...\n", philosopher->id);
		pthread_mutex_unlock(&philosopher->params->print_mutex);
		ft_usleep(philosopher->params->time_to_sleep);
	}
	else
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
}

// void	*philosopher_routine(void *arg)
// {
// 	t_philo		*philosopher;
// 	t_params	*params;

// 	philosopher = (t_philo *)arg;
// 	params = philosopher->params;
// 	while (1)
//     {
//         pthread_mutex_lock(&params->sim_run_mutex);
//         if (!params->sim_run)
//         {
//             pthread_mutex_unlock(&params->sim_run_mutex);
//             break;
//         }
//         pthread_mutex_unlock(&params->sim_run_mutex);
//         if (check_death(philosopher))
//             break;
//         philosopher_think(philosopher);
//         philosopher_eat(philosopher);
//         philosopher_sleep(philosopher);
//     }
// 	return (NULL);
// }

void *philosopher_routine(void *arg)
{
    t_philo *philosopher = (t_philo *)arg;
    t_params *params = philosopher->params;

	ft_usleep(10 * philosopher->id);
    while (1)
    {
        printf("Philosopher %d checking sim_run...\n", philosopher->id);
       	//pthread_mutex_lock(&philosopher->params->sim_run_mutex);
        if (!params->sim_run)
        {
            printf("Philosopher %d detected sim_run = 0, exiting.\n", philosopher->id);
            pthread_mutex_unlock(&params->sim_run_mutex);
            break;
        }
        pthread_mutex_unlock(&params->sim_run_mutex);

        if (check_death(philosopher))
        {
            printf("Philosopher %d has died, exiting routine.\n", philosopher->id);
            break;
        }

        printf("Philosopher %d is thinking...\n", philosopher->id);
        philosopher_think(philosopher);

        printf("Philosopher %d is eating...\n", philosopher->id);
        philosopher_eat(philosopher);

        printf("Philosopher %d is sleeping...\n", philosopher->id);
        philosopher_sleep(philosopher);
    }
    return (NULL);
}