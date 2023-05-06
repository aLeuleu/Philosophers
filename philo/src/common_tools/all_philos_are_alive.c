

#include "common_tools.h"

//returns false if any philo died
bool	all_philos_are_alive(t_philos_params *params)
{
	bool	return_value;

	pthread_mutex_lock(&params->a_philo_died_mutex);
	return_value = params->a_philo_died == false;
	pthread_mutex_unlock(&params->a_philo_died_mutex);
	return (return_value);
}
