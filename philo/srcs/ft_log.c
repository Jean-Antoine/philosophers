/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:29 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/15 18:49:35 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(char *log, t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print));
	if (!ft_stop(philo))
		printf("%8ld %3d %s\n", ft_get_time(philo->start), philo->id, log);
	pthread_mutex_unlock(&(philo->data->print));
}
