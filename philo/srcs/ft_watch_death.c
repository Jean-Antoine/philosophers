/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:51:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/14 16:20:23 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	ft_watcher(void	*args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	usleep(philo->data->time_to_die);
	pthread_lock
}

void	ft_watch_death(t_philo *philo)
{
	pthread_t	th;

	pthread_create(&th, NULL, *ft_watcher, philo);
	pthread_detach(th);
}
