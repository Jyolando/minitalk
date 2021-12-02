/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:01 by jyolando          #+#    #+#             */
/*   Updated: 2021/12/02 18:41:59 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void ft_handler(int sign, siginfo_t *si, void *unhandle)
{
	static char ch = 0;
	static int n = 1;

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

int main(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_putnbr(getpid());
	write(1, "\n", 1);

	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		write(1, "error", 5);
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		write(1, "error", 5);

	while (1)
		pause();
	return (0);
}
