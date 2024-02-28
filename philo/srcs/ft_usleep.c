/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:30:59 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 14:37:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, int ms)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (ft_get_time(start) < ms)
	{
		usleep(1000);
		if (!ft_continue(philo))
			break ;
	}
}
