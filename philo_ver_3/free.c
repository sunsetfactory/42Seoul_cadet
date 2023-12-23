#include "philo.h"

void	free_all(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->num)
	{
		pthread_mutex_destroy(&(rule->philo[i].eating));
		i++;
	}
	free(rule->philo);
	i = 0;
	pthread_mutex_destroy(&(rule->print));
	while (i < rule->num)
	{
		pthread_mutex_destroy(&(rule->forks[i]));
		i++;
	}
}

void	detach_thread(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->num)
	{
		pthread_detach(rule->philo[i].thread_id);
		i++;
	}
}
