/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:34:42 by jyolando          #+#    #+#             */
/*   Updated: 2021/09/22 22:18:32 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (n-- && (*ps1 || *ps2))
	{
		if (*ps1 - *ps2 != 0)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
	}
	return (0);
}
