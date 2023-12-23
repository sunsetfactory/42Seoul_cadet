#include "philo.h"

long long	set_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	die_check(t_rule *rule, t_philo *philo)
{
	int	i;

	while ((!(rule->die)) && rule->all_eat)
	{
		i = 0;
		while ((i < rule->num) && !(rule->die))
		{
			pthread_mutex_lock(&(philo->eating));
			if ((set_time() - philo->time_eat) > rule->t_die)
			{
				ft_printf(rule, "died", philo->index);
				rule->die = 1;
			}
			pthread_mutex_unlock(&(philo->eating));
			i++;
			usleep(100);
		}
		if (rule->die)
			break ;
	}
}
