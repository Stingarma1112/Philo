/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:05 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/22 17:09:20 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philosopher_think(t_philo *philosopher)
{
    pthread_mutex_lock(&philosopher->params->sim_run_mutex);
    if (philosopher->params->sim_run)
    {
        pthread_mutex_lock(&philosopher->params->print_mutex);
        pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
        printf("Philo %d is thinking at %ld ms\n", philosopher->id, get_time(philosopher->params));
        pthread_mutex_unlock(&philosopher->params->print_mutex);
    }
    else
    {
        pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
    }
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
        pthread_mutex_lock(&philosopher->params->print_mutex);
        pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
        printf("Philo %d is eating at %ld ms\n", philosopher->id, get_time(philosopher->params));
        pthread_mutex_unlock(&philosopher->params->print_mutex);
        philosopher->last_meal_time = get_time(philosopher->params);
        ft_usleep(philosopher->params->time_to_eat, philosopher->params);
    }
    else
    {
        pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
    }
    pthread_mutex_unlock(philosopher->right_fork);
    pthread_mutex_unlock(philosopher->left_fork);
}

void	philosopher_sleep(t_philo *philosopher)
{
    pthread_mutex_lock(&philosopher->params->sim_run_mutex);
    if (philosopher->params->sim_run)
    {
        pthread_mutex_lock(&philosopher->params->print_mutex);
        pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
        printf("Philo %d is sleeping at %ld ms\n", philosopher->id, get_time(philosopher->params));
        pthread_mutex_unlock(&philosopher->params->print_mutex);
        ft_usleep(philosopher->params->time_to_sleep, philosopher->params);
    }
    else 
    {
        pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
    }
}

void	*philosopher_routine(void *arg)
{
    t_philo		*philosopher;
    t_params	*params;

    philosopher = (t_philo *)arg;
    params = philosopher->params;
    while (1)
    {
        pthread_mutex_lock(&params->sim_run_mutex);
        if (!params->sim_run)
        {
            pthread_mutex_unlock(&params->sim_run_mutex);
            break;
        }
        pthread_mutex_unlock(&params->sim_run_mutex);
        if (check_death(philosopher))
            break;
        philosopher_think(philosopher);
        philosopher_eat(philosopher);
        philosopher_sleep(philosopher);
    }
    return (NULL);
}
