/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:05:05 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 14:10:56 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*ft_incr(void *arg)
{
	sem_t	*sem;

	sem = (sem_t *) arg;
	usleep(2000000);
	printf("Semaphore incremented by thread.\n");
	sem_post(sem);
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	pthread_t 	monitor;
	sem_t		*sem;
	
	sem = sem_open("sem", O_CREAT, S_IRWXU, 0);
	sem_unlink("sem");
	pthread_create(&monitor, NULL, ft_incr, (void *)sem);
	sem_wait(sem);
	printf("Passed wait.\n");
}