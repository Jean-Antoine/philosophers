/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 12:58:14 by jeada-si         ###   ########.fr       */
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
	int				odd;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				n_meal_needed;
	int				n_meal_min_time;
	int				stop;
	struct timeval	start;
	pthread_mutex_t	print;
	pthread_mutex_t	stop_m;
}	t_data;

typedef struct s_philo
{
	int				id;
	struct timeval	start;
	struct timeval	last_meal;
	int				n_meal;
	pthread_mutex_t	fork;
	pthread_mutex_t	started_eating;
	pthread_t		thread;
	t_data			*data;
	struct s_philo	*next;
}	t_philo;

void	ft_putendl_fd(char *s, int fd);
int		ft_exit(char *msg);
int		ft_parse_arg(const char *nptr);
int		ft_init_data(int ac, char **av, t_data *data);
t_philo	*ft_init_philo(t_data *data);
void	ft_free_list(t_philo *philo);
void	*ft_philo(void *data);
void	ft_launch(t_philo *philo);
void	ft_log(char *log, t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo, long ms);
long	ft_get_time(struct timeval time);
void	ft_monitor(t_philo *philo);
int		ft_continue(t_philo *philo);
void	ft_stop(t_philo *philo);
#endif