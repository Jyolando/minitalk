/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:33:06 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/04 16:33:06 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		res;
	long	neg;

	neg = 1;
	res = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		neg = -neg;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * neg);
}
