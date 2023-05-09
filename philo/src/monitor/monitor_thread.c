#include "philo.h"

static bool	check_if_a_philo_died(t_philo *philo);
static void	stop_philosophers(t_philos_params *params);
static bool	is_philosopher_dead(t_philo *philo);

//this will start the simulation by unlocking the "start simulation mutex"
void	*monitor_routine(void *philos_casted_to_void)
{
	t_philo *philos;

	philos = (t_philo *)philos_casted_to_void;
	usleep(500);
	philos->params->start_time = get_current_time();
	printf("monitor : starting ..\n");
	pthread_mutex_unlock(&philos->params->start_simulation_mutex);
	usleep(500);
		while (true)
			if (check_if_a_philo_died(philos))
				return (NULL);
}

static bool	check_if_a_philo_died(t_philo *philo)
{
	int				i;
	int				philo_has_finished;

	philo_has_finished = 0;
	i = philo->params->nb_philos;
	while (i--)
	{
//		printf("%i ...\n", i);
		if (is_philosopher_dead(philo + i))
		{
//			printf("stop1\n") ;//debug
			stop_philosophers(philo->params);
			printf("%lli\t%i died\n",
					get_timestamp(philo->params, get_current_time()),
					philo[i].id);
			return (true);
		}
		pthread_mutex_lock(&philo[i].nb_meals_eaten_mutex);
		philo_has_finished += philo[i].nb_meals_eaten >= philo->params->nb_of_meals_to_eat;
		pthread_mutex_unlock(&philo[i].nb_meals_eaten_mutex);
	}
	if (philo_has_finished == philo->params->nb_philos)
	{
		printf("stop2\n") ;//debug
		stop_philosophers(philo->params);
		return (true);
	}
	usleep(50);
	return (false);
}

static bool	is_philosopher_dead(t_philo *philo)
{
	const struct timeval	current_time = get_current_time();
	bool					return_value;

	pthread_mutex_lock(&philo->predicted_death_time_mutex);
//	printf("*philo->predicted_death_time : %lli\n", get_timestamp(philo->params, philo->predicted_death_time));
	return_value =
			timeval_compare(philo->predicted_death_time, current_time) <= 0;
	pthread_mutex_unlock(&philo->predicted_death_time_mutex);
	return (return_value);
}

static void	stop_philosophers(t_philos_params *params)
{
	pthread_mutex_lock(&params->a_philo_died_mutex);
	params->a_philo_died = true;
	pthread_mutex_unlock(&params->a_philo_died_mutex);
}
