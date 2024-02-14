/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:21:26 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/14 17:06:37 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_new_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->data = data;
	philo->n_meal = 0;
	if (pthread_mutex_init(&philo->fork, NULL))
	{
		free(philo);
		return (NULL);
	}
	if (pthread_mutex_init(&philo->eating, NULL))
	{
		pthread_mutex_destroy(&(philo->fork));
		free(philo);
		return (NULL);
	}
	return (philo);
}

t_philo	*ft_init_philo(t_data *data)
{
	t_philo	*list;
	t_philo	*philo;
	int		n;

	n = data->n;
	list = ft_new_philo(n, data);
	if (!list)
		return (NULL);
	philo = list;
	while (--n)
	{
		philo->next = ft_new_philo(n, data);
		philo = philo->next;
		if (!philo)
		{
			ft_free_list(list);
			return (NULL);
		}
	}
	philo->next = list;
	return (list);
}

int	ft_init_data(int ac, char **av, t_data *data)
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
		return (ft_exit("Error: All args must be strictly numeric, "
				"positive and fit into an integer."));
	if (data->n == 0)
		return (ft_exit("Error: number_of_philosophers must "
				"be strictly positive."));
	if (pthread_mutex_init(&(data->print), NULL))
		return (ft_exit("pthread_mutex_init: Something went wrong."));
	return (0);
}
