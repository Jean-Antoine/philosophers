/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:18:05 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 15:52:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_philo *philo)
{
	if (philo->eating && philo->eating != SEM_FAILED)
		sem_close(philo->eating);
	if (philo->dead && philo->dead != SEM_FAILED)
		sem_close(philo->dead);
	return ;
}
