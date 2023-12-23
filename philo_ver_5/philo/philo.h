/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:05:14 by ael-khni          #+#    #+#             */
/*   Updated: 2023/12/23 19:21:37 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define SCS 0
# define ERR 1

# define RIGHT 2
# define LEFT 3

enum e_bool
{
	false,
	true
};

typedef struct timeval	t_time;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int			id;
	int			ate;
	int			should_die;
	long long	last_meal;
	t_table		*table;
	pthread_t	thread;
}	t_philo;

typedef struct s_table
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_philo;
	int				num_must_eat;
	int				finish;
	int				all_ate;
	long long		creation_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_lock;
}	t_table;

/* UTILS FUNCTIONS */
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_puterr(char *err);
void		*ft_calloc(size_t count, size_t size);
long long	ft_current_time(t_philo *philo);
long long	ft_get_time(void);

/* INIT FUNCTIONS */
int			ft_check_table(t_table table, int ac);
int			ft_init_all(t_table *table, int ac, char **av);
void		ft_init_mutex(t_table *table);
void		ft_create_philos(t_table *table);
void		ft_get_args(t_table *table, int ac, char **av);

/* ACT FUNCTIONS */
void		down_fork(t_philo *philo, int f1, int f2);
void		grab_fork(t_philo *philo, int f, int c);
void		ft_join_free(t_table *table);
void		*philosophers(void *arg);
void		ft_print_msg(t_philo *philo, char *msg);
void		ft_eating(t_philo *philo);
void		sleep_then_think(t_philo *philo);

#endif
