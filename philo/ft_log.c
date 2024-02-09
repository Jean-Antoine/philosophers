/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:29 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/09 16:49:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_log(char *log, t_philo *philo)
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	pthread_mutex_lock(&(philo->args->print));
	printf("%8ld %d %s\n", (now.tv_usec - philo->start.tv_usec)/1000, philo->id, log);
	pthread_mutex_unlock(&(philo->args->print));
}

void	ft_log_fork(t_philo *philo)
{
	ft_log("has taken a fork", philo);
}

void	ft_log_eating(t_philo *philo)
{
	ft_log("is eating", philo);
}

void	ft_log_sleeping(t_philo *philo)
{
	ft_log("is sleeping", philo);
}

void	ft_log_thinking(t_philo *philo)
{
	ft_log("is thinking", philo);
}

void	ft_log_died(t_philo *philo)
{
	ft_log("died", philo);
}