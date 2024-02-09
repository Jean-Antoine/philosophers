/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/09 16:38:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# define INT_MAX 2147483647

typedef struct s_data
{	
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_eat_bf_end;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int				id;
	struct timeval	start;
	struct timeval	last_time_eat;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_data			*args;
	struct s_philo	*next;
}	t_philo;

void	ft_putendl_fd(char *s, int fd);
int		ft_exit(char *msg);
int		ft_parse_arg(const char *nptr);
int		ft_init_data(int ac, char **av, t_data *data);
t_philo	*ft_init_philo(t_data *data);
void	ft_free_list(t_philo *philo);
void	*ft_philo(void *args);
void	ft_run_threads(t_philo *philo);
void	ft_log_fork(t_philo *philo);
void	ft_log_eating(t_philo *philo);
void	ft_log_sleeping(t_philo *philo);
void	ft_log_thinking(t_philo *philo);
void	ft_log_died(t_philo *philo);
#endif