#include "philo.h"

void	taken_a_fork(t_rule *rule, t_philo *philo)
{
	pthread_mutex_lock(&(rule->forks[philo->lfork]));
	ft_printf(rule, "has taken a fork", philo->index);
	pthread_mutex_lock(&(rule->forks[philo->rfork]));
	ft_printf(rule, "has taken a fork", philo->index);
}

void	eating(t_rule *rule, t_philo *philo)
{
	pthread_mutex_lock(&(philo->eating));
	ft_printf(rule, "is eating", philo->index);
	philo->time_eat = set_time();
	pthread_mutex_unlock(&(philo->eating));
	while (!(rule->die))
	{
		if ((set_time() - philo->time_eat) >= rule->t_eat)
			break ;
		usleep(50);
	}
	(philo->count_eat)++;
	if ((philo->count_eat) == rule->c_eat)
		(rule->all_eat)--;
	pthread_mutex_unlock(&(rule->forks[philo->lfork]));
	pthread_mutex_unlock(&(rule->forks[philo->rfork]));
}

void	sleeping(t_rule *rule, t_philo *philo)
{
	long long	time;

	ft_printf(rule, "is sleeping", philo->index);
	time = set_time();
	while (!(rule->die))
	{
		if ((set_time() - time) >= rule->t_sleep)
			break ;
		usleep(50);
	}
}
