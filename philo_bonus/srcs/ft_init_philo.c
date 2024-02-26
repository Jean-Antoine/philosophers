/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:46:22 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 16:47:40 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(int id, t_philo *philo, t_data *data)
{
	philo->stop = 0;
	philo->n_meal = 0;
	philo->id = id;
	philo->last_meal.tv_sec = data->start.tv_sec;
	philo->last_meal.tv_usec = data->start.tv_usec;
	philo->eating = NULL;
	philo->data = data;
	philo->eating = sem_open("eating_local", O_CREAT, S_IRWXU, 1);
	if (philo->eating == SEM_FAILED)
		ft_exit(MSG_SEM, data, philo);
	sem_unlink("eating_local");
	philo->dead = sem_open("dead", O_CREAT, S_IRWXU, 1);
	if (philo->dead == SEM_FAILED)
		ft_exit(MSG_SEM, data, philo);	
	sem_unlink("dead");
}