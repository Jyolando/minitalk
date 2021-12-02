/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:37:57 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/07 14:37:57 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i++ <= (int)ft_strlen(s))
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
