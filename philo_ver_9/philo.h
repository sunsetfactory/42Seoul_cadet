/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:45:19 by minkylee          #+#    #+#             */
/*   Updated: 2023/11/15 10:44:36 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <sys/errno.h>

typedef enum e_print
{
	eating = 0,
	sleeping,
	thinking,
	taken,
	dead,
	complete
}	t_print;

typedef struct s_fork
{
	int				id;
	int				state;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			last_meal_time;
	long			start_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each;
	int				*alive;
	pthread_mutex_t	*time_mutex;
	pthread_mutex_t	*alive_mutex;
	pthread_mutex_t	*print_mutex;
}	t_philo;

typedef struct s_simul
{
	t_philo			*philo;
	t_fork			*forks;
	int				num_of_philo;
	int				eat_flag;
	int				alive;
	pthread_t		*philo_threads;
	pthread_t		*monitor_thread;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	print_mutex;
}				t_simul;

int		ft_atoi(const char *str);
long	get_time(void);
void	ft_usleep(long sleep_time);
int		check_argu(int argc, char **argv);

t_fork	*init_forks(int num_of_philo);
void	init_philo(int argc, char **argv, t_philo *philo, int id);
int		malloc_simul(t_simul *sim);
void	init_simul(t_simul *sim, int argc, char **argv);

int		check_alive(t_philo *philo);
int		eating_count(t_philo *philo, t_simul *monitor, int *check_num);
int		monitoring_sys(t_simul *monitor);
void	*monitoring_routine(void *arg);

void	is_valid_fork(t_philo *philo);
void	eat(t_philo *philo);
void	*routine(void *argu);

void	create_philosophers(t_simul *sim);
void	join_philosophers(t_simul *sim);
void	clean_up(t_simul *sim);

void	print(t_philo *philo, t_print print, long timeline);

#endif
