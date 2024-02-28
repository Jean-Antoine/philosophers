/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_kill_signal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:47:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 15:47:14 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_send_kill_signal(t_data *data)
{
	pthread_mutex_lock(&(data->stop_m));
	data->stop = 1;
	pthread_mutex_unlock(&(data->stop_m));
}
