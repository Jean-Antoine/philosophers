/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/21 16:32:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		ft_exit(MSG_INPUT, NULL, NULL);
	ft_init_data(ac, av, &data);
	ft_launch(data.args.n, &data);
	ft_wait(data.args.n, &data);
	ft_free_data(&data);
	// printf("BACK");
	return (1);
}
