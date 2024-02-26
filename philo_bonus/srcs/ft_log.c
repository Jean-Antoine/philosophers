/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:29 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 12:08:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(t_philo *philo, t_data *data, char *log)
{
	sem_wait(data->print);
	if (!philo->stop)
		printf("%8ld %3d %s\n", ft_get_time(data->start),
			philo->id,
			log);
	sem_post(data->print);
}
