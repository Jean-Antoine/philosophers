/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/18 17:27:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_launch(t_data *data)
{
	int				n;

	n = data->n;
	gettimeofday(&(data->start), NULL);
	while (n--)
	{
		data->philo[n] = fork();
		if (data->philo[n] == -1)
			ft_exit("Error: fork()", data);
		if (data->philo[n] == 0)
			ft_philo(n, data);
	}
	ft_monitor(data);
}
