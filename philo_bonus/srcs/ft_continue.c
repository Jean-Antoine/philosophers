/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_continue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/17 17:39:59 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_continue(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&(philo->data->stop_m));
	stop = philo->data->stop;
	pthread_mutex_unlock(&(philo->data->stop_m));
	return (!stop);
}
