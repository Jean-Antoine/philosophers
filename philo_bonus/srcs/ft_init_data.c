/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:21:26 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 14:53:58 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_parse(int ac, char **av, t_args *args)
{
	args->n = ft_parse_arg(av[1]);
	args->time_to_die = ft_parse_arg(av[2]);
	args->time_to_eat = ft_parse_arg(av[3]);
	args->time_to_sleep = ft_parse_arg(av[4]);
	if (ac == 6)
		args->n_meal_needed = ft_parse_arg(av[5]);
	else
		args->n_meal_needed = -2;
	if (args->n == -1
		|| args->time_to_die == -1
		|| args->time_to_eat == -1
		|| args->time_to_sleep == -1
		|| args->n_meal_needed == -1)
		ft_exit(MSG_NUMERIC, NULL, NULL);
	args->n_meal_min_time = args->time_to_eat * args->n_meal_needed
		+ args->time_to_sleep * (args->n_meal_needed - 1);
	return ;
}

static void	ft_sem_open(t_data *data)
{
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->args.n);
	data->all_eaten = sem_open("all_eaten", O_CREAT, S_IRWXU, data->args.n);
	data->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	data->kill = sem_open("kill", O_CREAT, S_IRWXU, data->args.n);
	data->before_fork = sem_open("before_fork", O_CREAT, S_IRWXU, data->args.n / 2);
	if (data->print == SEM_FAILED
		|| data->forks == SEM_FAILED
		|| data->all_eaten == SEM_FAILED
		|| data->kill == SEM_FAILED
		|| data->before_fork == SEM_FAILED)
		ft_exit(MSG_SEM, data, NULL);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("all_eaten");
	sem_unlink("kill");
	sem_unlink("before_fork");
}

void	ft_init_data(int ac, char **av, t_data *data)
{
	data->philo = NULL;
	data->print = NULL;
	data->forks = NULL;
	data->kill = NULL;
	data->all_eaten = NULL;
	data->before_fork = NULL;
	ft_parse(ac, av, &(data->args));
	ft_sem_open(data);
	data->philo = (pid_t *) malloc(sizeof(pid_t) * data->args.n);
	if (!data->philo)
		ft_exit(MSG_MALLOC, data, NULL);
	return ;
}
