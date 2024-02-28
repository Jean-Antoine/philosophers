/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 16:48:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# define INT_MAX 2147483647
# define MSG_EMPTY 0
# define MSG_INPUT 1
# define MSG_MALLOC 2
# define MSG_SEM 3
# define MSG_NUMERIC 4
# define MSG_FORK 5

typedef struct s_args
{
	int				n;
	int				odd;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				n_meal_needed;
	int				n_meal_min_time;
}	t_args;

typedef struct s_data
{
	t_args			args;
	struct timeval	start;
	sem_t			*all_eaten;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*kill;
	pid_t			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				n_meal;
	int				stop;
	struct timeval	last_meal;
	sem_t			*eating;
	sem_t			*dead;
	t_data			*data;
}	t_philo;

//PARENT
int		ft_parse_arg(const char *nptr);
void	ft_init_data(int ac, char **av, t_data *data);
void	ft_free_data(t_data *data);
void	ft_launch(int n, t_data *data);
void	ft_wait(int n, t_data *data);

//PHILO
void	ft_init_philo(int id, t_philo *philo, t_data *data);
void	ft_philo(int id, t_data *data);
void	ft_free_philo(t_philo *philo);
void	ft_log(t_philo *philo, t_data *data, char *log);
void	ft_eat(t_philo *philo, t_data *data);
void	ft_sleep(t_philo *philo, t_data *data);
void	ft_think(t_philo *philo, t_data *data, long ms);
long	ft_get_time(struct timeval time);
void	*ft_monitor_death(void *arg);
void	*ft_monitor_killed(void *args);
void	*ft_monitor_eaten_enough(void *args);
int		ft_is_dead(t_philo *philo);

//CROSS
void	ft_usleep(t_philo *philo, int ms);
void	ft_send_kill_signal(t_data *data);
void	ft_putendl_fd(char *s, int fd);
void	ft_exit(int msg, t_data *data, t_philo *philo);
#endif