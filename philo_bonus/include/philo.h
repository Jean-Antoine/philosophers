/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/18 17:27:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# define INT_MAX 2147483647

typedef struct s_data
{
	int				n;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meal_needed;
	int				n_meal_min_time;
	struct timeval	start;
	sem_t			*print;
	sem_t			*forks;
	pid_t			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	struct timeval	start;
	struct timeval	last_meal;
	int				n_meal;
	pthread_mutex_t	started_eating;
	pid_t			pid;
	t_data			*data;
	struct s_philo	*next;
}	t_philo;

void	ft_putendl_fd(char *s, int fd);
int		ft_exit(char *msg, t_data *data);
int		ft_parse_arg(const char *nptr);
void	ft_init_data(int ac, char **av, t_data *data);
void	ft_free_data(t_data *data);
void	ft_philo(int id, t_data *data);
void	ft_launch(t_data *data);
void	ft_log(char *log, t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo, long ms);
long	ft_get_time(struct timeval time);
void	ft_monitor(t_philo *philo);
int		ft_continue(t_philo *philo);
void	ft_stop(t_philo *philo);
#endif