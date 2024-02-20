/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/19 17:58:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		exit_code;

	if (ac < 5 || ac > 6)
		ft_exit(NULL, NULL, 1);
	ft_init_data(ac, av, &data);
	ft_launch(data.n, &data);
	exit_code = ft_wait(data.n, data.philo);
	ft_free_data(&data);
	return (exit_code);
}
