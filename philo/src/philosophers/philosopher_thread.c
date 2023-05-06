#include "philo.h"

static void init_philosopher_thread(t_philo *philo, t_philos_params *params);

void	*philosopher_thread(void *philosopher_casted_to_void)
{
	t_philo					*philo;

	philo = (t_philo *)philosopher_casted_to_void;
	init_philosopher_thread(philo, philo->params);
	while (true)
	{
		if (philosopher_eats(philo) < 0)
			return (NULL);
		if (philosopher_sleeps(philo) < 0)
			return (NULL);
		if (print_state_change("%lli\t%i is thinking\n", philo, philo->params) < 0)
			break ;
		usleep(100);
	}
}

static void init_philosopher_thread(t_philo *philo, t_philos_params *params)
{
	struct timeval tmp;

	pthread_mutex_lock(&params->start_simulation_mutex);
	pthread_mutex_unlock(&params->start_simulation_mutex);

	pthread_mutex_lock(&philo->predicted_death_time_mutex);
	philo->predicted_death_time = params->start_time;
	timeval_add_ms(&philo->predicted_death_time, params->time_to_die);
	pthread_mutex_unlock(&philo->predicted_death_time_mutex);
	if (philo->id % 2)
	{
		tmp = params->start_time;
		timeval_add_ms(&tmp, 10);
		if (print_state_change("%lli\t%i is thinking\n", philo, params) < 0)
			return ;
		sleep_till(tmp, philo);
		return ;
	}
}