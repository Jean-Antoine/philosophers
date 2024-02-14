/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:02:14 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/14 13:05:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - time.tv_sec) * 1000)
		+ ((now.tv_usec - time.tv_usec) / 1000));
}
