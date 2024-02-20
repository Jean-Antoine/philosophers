/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:47:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/20 14:14:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_bucle(int n)
{
	static int	i = 0;

	if (i == n - 1)
		i = 0;
	else
		i++;
	return (i);
}

static int	ft_killall(int n, pid_t *philo)
{
	while (n--)
		if (philo[n] != -1)
			kill(philo[n], SIGTERM);
	return (1);
}

int	ft_wait(int n, pid_t *philo)
{
	int	n_eaten_enough;
	int	i;
	int	status;

	n_eaten_enough = 0;
	i = 0;
	while (n_eaten_enough != n)
	{
		// printf("i = %d\n", i);
		if (philo[i] != -1
			&& waitpid(philo[i], &status, WNOHANG) != 0)
		{
			
			if (WEXITSTATUS(status) == DEAD)
				return (ft_killall(n, philo));
			else if (WEXITSTATUS(status) == EATEN_ENOUGH)
			{
				philo[i] = -1;
				n_eaten_enough++;
			}
			else
				return (1);
		}
		i = ft_bucle(n);
	}
	return (0);
}
