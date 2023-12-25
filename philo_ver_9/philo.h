/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:45:19 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:45:05 by seokjyan         ###   ########.fr       */
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
	fork,
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
	long			last_meal;
	long			start_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_time_each;
	int				*alive;
	pthread_mutex_t	*time_lock;
	pthread_mutex_t	*alive_lock;
	pthread_mutex_t	*print_lock;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	t_fork			*forks;
	int				num_philo;
	int				eat_flag;
	int				alive;
	pthread_t		*philo_threads;
	pthread_t		*monitor_thread;
	pthread_mutex_t	alive_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	print_lock;
}				t_table;

void	eat(t_philo *philo);
void	*routine(void *argu);
void	create_philo(t_table *table);
void	join_philo(t_table *table);
void	clean_up(t_table *table);
void	print(t_philo *philo, t_print print, long timeline);
t_fork	*init_forks(int num_philo);
void	init_philo(int argc, char **argv, t_philo *philo, int id);
int		malloc_tableul(t_table *table);
void	init_table(t_table *table, int argc, char **argv);
int		ft_atoi(const char *str);
long	ft_get_time(void);
void	ft_usleep(long sleep_time);
int		check_argu(int argc, char **argv);
void	is_valid_fork(t_philo *philo);
int		check_alive(t_philo *philo);
int		eating_count(t_philo *philo, t_table *monitor, int *check_num);
int		monitoring_sys(t_table *monitor);
void	*ft_mornitoring(void *arg);

#endif
