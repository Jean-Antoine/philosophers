SRCS				= main.c\
						ft_putendl_fd.c\
						ft_exit.c\
						ft_parse_arg.c\
						ft_init.c\
						ft_free_list.c\
						ft_run_threads.c\
						ft_philo.c\
						ft_log.c	
OBJS				= $(SRCS:.c=.o)

CC					= cc
CPPFLAGS			= -I.
CFLAGS				= -Wall -Wextra -Werror -g
NAME				= philo

all					: $(NAME)

$(NAME)				: $(OBJS)
					  $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean				:
					  rm -f $(OBJS)

fclean				: clean
					  rm -f $(NAME)

re					: fclean $(NAME)