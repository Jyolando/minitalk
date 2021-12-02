/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:00:10 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/04 21:00:10 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*source;

	if (!src && !dest)
		return (NULL);
	str = (char *)dest;
	source = (char *)src;
	while (n--)
	{
		*(str)++ = *(source)++;
	}
	return (dest);
}
