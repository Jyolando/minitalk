/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:53:11 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/07 21:53:11 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
