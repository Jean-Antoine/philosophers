/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/20 14:44:07 by jeada-si         ###   ########.fr       */
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
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# define INT_MAX 2147483647

typedef struct s_data
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meal_needed;
	int				n_meal_min_time;
	struct timeval	start;
	sem_t			*eaten_enough;
	sem_t			*eating;
	sem_t			*print;
	sem_t			*forks;
	pid_t			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				n_meal;
	struct timeval	last_meal;
	sem_t			*eaten_enough;
	sem_t			*eating;
}	t_philo;

void	ft_putendl_fd(char *s, int fd);
void	ft_exit(char *msg, t_data *data, int exit_code);
int		ft_parse_arg(const char *nptr);
void	ft_init_data(int ac, char **av, t_data *data);
void	ft_free_data(t_data *data);
void	ft_philo(int id, t_data *data);
void	ft_launch(int n, t_data *data);
void	ft_log(int id, t_data *data, char *log);
void	ft_eat(int id, t_data *data);
void	ft_sleep(int id, t_data *data);
void	ft_think(int id, t_data *data, long ms);
long	ft_get_time(struct timeval time);
int		ft_wait(int n, pid_t *philo);
void	*ft_monitor(void *arg);
#endif