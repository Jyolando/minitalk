/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:57:23 by jyolando          #+#    #+#             */
/*   Updated: 2021/09/29 21:04:05 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;

	if (!big && !little)
		return (NULL);
	if (!little[0] && little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < size)
	{
		j = 0;
		while (big[i + j] && little[j] && i + j < size
			&& big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
