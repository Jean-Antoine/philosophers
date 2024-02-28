SRCS_D				= ./srcs/
OBJS_D				= ./objs/
SRCS_F				= main.c\
						ft_putendl_fd.c\
						ft_exit.c\
						ft_parse_arg.c\
						ft_init_data.c\
						ft_init_philo.c\
						ft_free_data.c\
						ft_free_philo.c\
						ft_launch.c\
						ft_philo.c\
						ft_log.c\
						ft_get_time.c\
						ft_eat.c\
						ft_think.c\
						ft_sleep.c\
						ft_monitor_eaten_enough.c\
						ft_monitor_killed.c\
						ft_monitor_death.c\
						ft_wait.c\
						ft_is_dead.c\
						ft_send_kill_signal.c\
						ft_usleep.c
OBJS_F				= $(SRCS_F:.c=.o)
SRCS				= $(addprefix $(SRCS_D), $(SRCS_F))
OBJS				= $(addprefix $(OBJS_D), $(OBJS_F))
CC					= cc
CPPFLAGS			= -I./include
CFLAGS				= -Wall -Wextra -Werror -g
NAME				= philo

all					: $(NAME)

bonus				: $(NAME)

$(OBJS_D)%.o		: $(SRCS_D)%.c
					  @mkdir -p $(OBJS_D)
					  $(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@

$(NAME)				: $(OBJS)
					  $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean				:
					  rm -f $(OBJS)

fclean				: clean
					  rm -f $(NAME)

re					: fclean $(NAME)

echo:
	echo $(OBJS)