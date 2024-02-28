/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 15:19:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(t_philo *philo)
{
	int	n;

	n = philo->data->n;
	while (n--)
	{
		if (philo->thread)
			pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}
