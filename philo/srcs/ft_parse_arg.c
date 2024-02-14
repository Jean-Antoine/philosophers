/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:47:09 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/09 11:34:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_parse_arg(const char *nptr)
{
	unsigned int	out;

	if (!nptr || !*nptr)
		return (-1);
	out = 0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (-1);
		out = out * 10 + (*nptr++ - '0');
		if (out > INT_MAX)
			return (-1);
	}
	return ((int) out);
}
