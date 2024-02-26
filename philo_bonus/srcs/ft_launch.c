/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 14:59:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_launch(int n, t_data *data)
{
	gettimeofday(&(data->start), NULL);
	n = data->args.n;
	while (n--)
	{
		data->philo[n] = fork();
		if (data->philo[n] == -1)
			ft_exit(MSG_FORK, data, NULL);
		if (data->philo[n] == 0)
			ft_philo(n, data);
	}
}
