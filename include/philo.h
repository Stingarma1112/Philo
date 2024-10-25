/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:23:04 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/25 22:27:47 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_params
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	sim_run_mutex;
	pthread_mutex_t	finish_mutex;
	int				sim_run;
	int				philosophers_finished;
	long			start_time;
}					t_params;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time;
	pthread_mutex_t	meal_time_mutex;
	int				meals_eaten;
	t_params		*params;
}					t_philo;

// INIT.C
int					validate_params(t_params *params);
int					init_params(t_params *params, int argc, char **argv);
int					init_fork_mutexes(t_params *params);
int					init_other_mutexes(t_params *params);
int					init_philosophers(t_philo *philosophers, t_params *params);

// PARSING.C
int					parsing(t_philo **philo, t_params *params, int argc,
						char **argv);
void				safe_print(t_philo *philosopher, char *message);
int					check_simulation_status(t_philo *philosopher);
int					check_meals_finished(t_philo *philosopher);
int					is_digit_string(char *str);

// SHIELD.C
void				free_resources(t_philo *philosophers, t_params *params,
						int count);
void				ft_usleep(long time_in_ms, t_philo *philosopher);
long				get_time(t_params *params);
long				get_current_time_in_ms(void);
int					validate_arguments(int argc, char **argv);

// ACTION.C
void				philosopher_think(t_philo *philosopher);
void				philosopher_eat(t_philo *philosopher);
void				philosopher_take_forks(t_philo *philosopher);
void				philosopher_sleep(t_philo *philosopher);
void				one_philo_one_fork(t_philo *philosopher);

// ROUTINE.C
void				*philosopher_routine(void *arg);
void				check_philosopher_death(t_philo *philosophers,
						t_params *params, int i);
int					check_all_finished(t_philo *philosophers, t_params *params);
void				*monitor_routine(void *arg);
int					monitor_philosophers(t_philo *philosophers,
						t_params *params);

#endif