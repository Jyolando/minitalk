/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:41:16 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/08 17:41:16 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (!src && !dest)
		return (NULL);
	pdest = (char *)dest;
	psrc = (char *)src;
	if (pdest < psrc)
	{
		while (n--)
			*(pdest)++ = *(psrc)++;
	}
	else
	{
		pdest = pdest + n;
		psrc = psrc + n;
		while (n--)
			*--(pdest) = *--(psrc);
	}
	return (dest);
}

// hello - ello - llo - 3
