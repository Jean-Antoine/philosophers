/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:40:25 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 14:40:22 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo, long ms)
{
	if (!ft_continue(philo))
		return ;
	ft_log("is thinking", philo);
	if (ms > 0)
		ft_usleep(philo, ms);
}
