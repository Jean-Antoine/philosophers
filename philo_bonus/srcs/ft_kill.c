/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:20:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/22 11:09:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_kill(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) args;
	data = philo->data;
	sem_wait(data->kill);
	sem_wait(data->print);
	sem_wait(philo->dead);
	philo->stop = 1;
	sem_post(philo->dead);
	sem_post(data->print);
	return (NULL);
}
