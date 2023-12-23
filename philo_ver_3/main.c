#include "philo.h"

void	*work_thread(void *v_philo)
{
	t_rule	*rule;
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	rule = philo->rule;
	if (philo->index % 2)
		usleep(10000);
	while ((!(rule->die)) && rule->all_eat)
	{
		taken_a_fork(rule, philo);
		eating(rule, philo);
		if ((!(rule->all_eat)) || rule->die)
			break ;
		sleeping(rule, philo);
		ft_printf(rule, "is thinking", philo->index);
	}
	return (0);
}

int	start_thread(t_rule *rule)
{
	int		i;
	t_philo	*v_philo;

	rule->t_start = set_time();
	i = 0;
	v_philo = (t_philo *)(rule->philo);
	while (i < rule->num)
	{
		if (pthread_create(&(rule->philo[i].thread_id), \
			NULL, work_thread, &(v_philo[i])))
			return (1);
		i++;
	}
	die_check(rule, rule->philo);
	detach_thread(rule);
	free_all(rule);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (argc < 5 || argc > 6)
		return (printf("Error : wrong input\n"));
	if (init_rule(&rule, argv))
	{
		free_all(&rule);
		return (printf("Error : worng input value\n"));
	}
	if (start_thread(&rule))
		return (printf("Error : thread error\n"));
	return (0);
}
