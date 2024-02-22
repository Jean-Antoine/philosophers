/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/22 11:43:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sem_post_n(sem_t *sem, int n)
{
	while (n--)
		sem_post(sem);
}

void	*ft_monitor(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		since_last_meal;
	int		n_meal;
	int		sem_posted;

	philo = (t_philo *) args;
	data = philo->data;
	sem_posted = 0;
	while (!ft_dead(philo))
	{
		sem_wait(philo->eating);
		since_last_meal = ft_get_time(philo->last_meal);
		n_meal = philo->n_meal;
		sem_post(philo->eating);
		if (since_last_meal > data->args.time_to_die)
		{
			ft_log(philo, data, "died");
			ft_sem_post_n(data->kill, data->args.n);
			return (NULL);
		}
		if (n_meal == data->args.n_meal_needed && !sem_posted)
		{
			sem_posted = 1;
			sem_post(data->all_eaten);
		}
	}
	return (NULL);
}
