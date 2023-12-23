#include "philo.h"

int	init_philo(t_rule *rule)
{
	int	i;

	i = 0;
	rule->philo = (t_philo *)malloc(sizeof(t_philo) * rule->num);
	if (!(rule->philo))
		return (1);
	while (i < rule->num)
	{
		rule->philo[i].index = i;
		rule->philo[i].lfork = i;
		rule->philo[i].rfork = (i + 1) % rule->num;
		rule->philo[i].count_eat = 0;
		rule->philo[i].time_eat = set_time();
		rule->philo[i].rule = rule;
		if (pthread_mutex_init(&(rule->philo[i].eating), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_thread(t_rule *rule)
{
	int				i;
	pthread_mutex_t	*tmp;

	tmp = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * rule->num);
	rule->forks = tmp;
	if (!(rule->forks))
		return (1);
	i = 0;
	while (i < rule->num)
	{
		if (pthread_mutex_init(&(rule->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(rule->print), NULL))
		return (1);
	return (0);
}

int	init_rule(t_rule *rule, char **argv)
{
	rule->num = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		rule->c_eat = ft_atoi(argv[5]);
		if (rule->c_eat <= 0)
			return (1);
	}
	else
		rule->c_eat = -1;
	rule->philo = 0;
	rule->t_start = set_time();
	rule->die = 0;
	rule->all_eat = rule->num;
	if (rule->num < 1 || rule->t_die <= 0 || \
		rule->t_eat < 0 || rule->t_sleep < 0)
		return (1);
	if (init_thread(rule) || init_philo(rule))
		return (1);
	return (0);
}
