#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

struct s_rule;

typedef struct s_philo
{
	int index;
	int lfork;
	int rfork;
	int count_eat;
	long long time_eat;
	pthread_t thread_id;
	struct s_rule *rule;
	pthread_mutex_t eating;
} t_philo;

typedef struct s_rule
{
	int num;
	int t_die;
	int t_eat;
	int t_sleep;
	int c_eat;
	t_philo *philo;
	long long t_start;
	int die;
	int all_eat;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
} t_rule;

void detach_thread(t_rule *rule);
void free_all(t_rule *rule);

int init_philo(t_rule *rule);
int init_thread(t_rule *rule);
int init_rule(t_rule *rule, char **argv);

void taken_a_fork(t_rule *rule, t_philo *philo);
void eating(t_rule *rule, t_philo *philo);
void sleeping(t_rule *rule, t_philo *philo);

long long set_time(void);
void die_check(t_rule *rule, t_philo *philo);

void ft_printf(t_rule *rule, char *str, int idx);
int ft_atoi(const char *str);

#endif
