SRCS_D				= ./srcs/
OBJS_D				= ./objs/
SRCS_F				= main.c\
						ft_putendl_fd.c\
						ft_exit.c\
						ft_parse_arg.c\
						ft_init.c\
						ft_free_list.c\
						ft_launch.c\
						ft_philo.c\
						ft_log.c\
						ft_get_time.c\
						ft_eat.c\
						ft_think.c\
						ft_sleep.c
OBJS_F				= $(SRCS_F:.c=.o)
SRCS				= $(addprefix $(SRCS_D), $(SRCS_F))
OBJS				= $(addprefix $(OBJS_D), $(OBJS_F))
CC					= cc
CPPFLAGS			= -I./include
CFLAGS				= -Wall -Wextra -Werror -g
NAME				= philo

all					: $(NAME)

$(OBJS_D)%.o		: $(SRCS_D)%.c
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