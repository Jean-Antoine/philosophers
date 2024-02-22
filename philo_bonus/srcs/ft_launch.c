/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/22 11:39:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sem_wait_n(sem_t *sem, int n)
{
	while (n--)
		sem_wait(sem);	
}

void	ft_launch(int n, t_data *data)
{
	gettimeofday(&(data->start), NULL);
	ft_sem_wait_n(data->kill, n);
	ft_sem_wait_n(data->all_eaten, n);
	while (n--)
	{
		data->philo[n] = fork();
		if (data->philo[n] == -1)
			ft_exit(MSG_FORK, data, NULL);
		if (data->philo[n] == 0)
			ft_philo(n, data);
	}
}
