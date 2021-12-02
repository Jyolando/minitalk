/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:01 by jyolando          #+#    #+#             */
/*   Updated: 2021/12/03 00:38:30 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

static void	ft_handler(int sign, siginfo_t *si, void *unhandle)
{
	static char	ch = 0;
	static int	n = 1;

	(void)unhandle;
	if (sign == SIGUSR1)
		ch |= n;
	n *= 2;
	if (n == 256)
	{
		write(1, &ch, 1);
		ch = 0;
		n = 1;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	write(1, "Current PID: ", 13);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		write(1, "Error signal!", 5);
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		write(1, "Error signal!", 5);
	while (1)
		pause();
	return (0);
}
