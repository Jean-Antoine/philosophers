/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:47:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/27 10:37:21 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_monitor_all_eaten(void *args)
{
	t_data	*data;
	int		n;

	data = (t_data *) args;
	n = data->args.n;
	while (n--)
		sem_wait(data->all_eaten);
	ft_send_kill_signal(data);
	return (NULL);
}

void	ft_wait(int n, t_data *data)
{
	int			i;
	pthread_t	all_eaten;
	int			status;

	i = 0;
	if (data->args.n_meal_needed > 0)
		pthread_create(&all_eaten, NULL, ft_monitor_all_eaten, (void *)data);
	while (i < n)
		waitpid(data->philo[i++], &status, 0);
	if (data->args.n_meal_needed > 0)
		pthread_join(all_eaten, NULL);
	return ;
}
