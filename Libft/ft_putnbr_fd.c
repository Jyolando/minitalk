/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:52:35 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/09 23:49:13 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}
