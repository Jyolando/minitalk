/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:52:13 by jyolando          #+#    #+#             */
/*   Updated: 2021/12/03 00:38:50 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_putstr(char *s)
{
	while (*s)
		write(1, &(*s++), 1);
}

static void	converter(int pid, char c)
{
	int	n;

	n = 1;
	while (n != 128)
	{
		if ((c & n) > 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("Error signal!\n");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("Error signal!\n");
				exit(0);
			}
		}
		n *= 2;
		usleep(100);
	}
}

static void	ft_sender(int pid, char *str)
{
	while (*str)
		converter(pid, *str++);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || ft_atoi(argv[1]) == 0)
		ft_putstr("Enter right arguments: ./client [PID] [Message]\n");
	else
		ft_sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}
