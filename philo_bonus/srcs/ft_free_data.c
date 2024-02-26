/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:27:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 11:33:12 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_data(t_data *data)
{
	if (data->philo)
		free(data->philo);
	if (data->forks && data->forks != SEM_FAILED)
		sem_close(data->forks);
	if (data->print && data->print != SEM_FAILED)
		sem_close(data->print);
	if (data->all_eaten && data->all_eaten != SEM_FAILED)
		sem_close(data->all_eaten);
	if (data->kill && data->kill != SEM_FAILED)
		sem_close(data->kill);
	if (data->before_fork && data->before_fork != SEM_FAILED)
		sem_close(data->before_fork);
	return ;
}
