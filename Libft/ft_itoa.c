/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:50:08 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/08 22:50:08 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static int	ft_numlen(int n, int neg)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size + neg);
}

char	*ft_itoa(int n)
{
	int		nsize;
	char	*nchar;
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	nsize = ft_numlen(n, neg);
	nchar = (char *)malloc((nsize + 1) * sizeof(char));
	if (!nchar)
		return (NULL);
	if (neg)
		nchar[0] = '-';
	nchar[nsize--] = '\0';
	while (nsize >= neg)
	{
		nchar[nsize--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (nchar);
}
