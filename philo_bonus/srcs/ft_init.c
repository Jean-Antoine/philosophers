/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:21:26 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/20 14:34:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_parse(int ac, char **av, t_data *data)
{
	data->n = ft_parse_arg(av[1]);
	data->time_to_die = ft_parse_arg(av[2]);
	data->time_to_eat = ft_parse_arg(av[3]);
	data->time_to_sleep = ft_parse_arg(av[4]);
	if (ac == 6)
		data->n_meal_needed = ft_parse_arg(av[5]);
	else
		data->n_meal_needed = -2;
	if (data->n == -1
		|| data->time_to_die == -1
		|| data->time_to_eat == -1
		|| data->time_to_sleep == -1
		|| data->n_meal_needed == -1)
		ft_exit("Error: All args must be strictly numeric, "
			"positive and fit into an integer.", NULL, 1);
	if (data->n == 0)
		ft_exit("Error: number_of_philosophers must "
			"be strictly positive.", NULL, 1);
	return ;
}

void	ft_init_data(int ac, char **av, t_data *data)
{
	ft_parse(ac, av, data);
	data->forks = NULL;
	data->print = NULL;
	data->philo = NULL;
	data->eating = NULL;
	data->eaten_enough = NULL;
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->n);
	data->eaten_enough = sem_open("eaten_enough", O_CREAT, S_IRWXU, data->n);
	data->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	if (data->print == SEM_FAILED || data->forks == SEM_FAILED)
		ft_exit("Error: sem_open", data, 1);
	sem_unlink("forks");
	sem_unlink("print");
	data->philo = (pid_t *) malloc(sizeof(pid_t) * data->n);
	if (!data->philo)
		ft_exit("Error: malloc", data, 1);
	data->n_meal_min_time = data->time_to_eat * data->n_meal_needed
		+ data->time_to_sleep * (data->n_meal_needed - 1);
	data->n_meal = 0;
	return ;
}
