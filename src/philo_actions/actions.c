#include "philosophers.h"

void	go_to_sleep(t_philo *philo)
{
	ft_printf("sleeping", philo);
	ft_usleep(philo->philo_gen->time_to_sleep);
}

void	go_to_eat(t_philo *philo)
{
while(1)
	{
	go_take_fork(philo);
	ft_printf("has eating", philo);
	ft_usleep(philo->philo_gen->time_to_eat);
	philo->fix_time= ft_time();
	go_put_fork(philo);
	go_to_sleep(philo);
	}
}

void	go_take_fork(t_philo *philo)
{
	pthread_mutex_lock((philo->left_fork));
	ft_printf("has taken a right fork", philo);
	pthread_mutex_lock((philo->right_fork));
	ft_printf("has taken a left fork", philo);
	
}

void	go_put_fork(t_philo *philo)
{
	pthread_mutex_unlock((philo->left_fork));
	pthread_mutex_unlock((philo->right_fork));
}


