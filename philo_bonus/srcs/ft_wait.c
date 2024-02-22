/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:47:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sem_post_n(sem_t *sem, int n)
{
	while (n--)
		sem_post(sem);
}

static void	*ft_all_eaten(void *args)
{
	t_data	*data;
	int		n;

	data = (t_data *) args;
	n = data->args.n;
	while (n--)
	{
		sem_wait(data->all_eaten);
	}
	ft_sem_post_n(data->kill, data->args.n);
	return (NULL);
}

void	ft_wait(int n, t_data *data)
{
	int			i;
	pthread_t	all_eaten;

	i = 0;
	pthread_create(&all_eaten, NULL, ft_all_eaten, (void *)data);
	while (i < n)
		waitpid(data->philo[i++], NULL, 0);
	while (1)
		if (sem_post(data->all_eaten))
			break;
	pthread_join(all_eaten, NULL);
	return ;
}
