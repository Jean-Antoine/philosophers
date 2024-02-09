/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:03:54 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/09 13:24:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_list(t_philo *philo)
{
	t_philo	*node;
	t_philo	*temp;

	if (!philo)
		return ;
	node = philo;
	while (node && node->next != philo)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(node);
}
