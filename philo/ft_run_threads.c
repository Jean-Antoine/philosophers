/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/09 16:39:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_run_threads(t_philo *philo)
{
	int		n;

	n = philo->args->n;
	while (n--)
	{
		pthread_create(&(philo->thread), NULL, *ft_philo, philo);
		gettimeofday(&philo->start, NULL);
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
	// n = data->n;
	// while (n--)
	// {
	// 	pthread_join(node->thread, NULL);
	// 	node = node->next;		
	// }
}
