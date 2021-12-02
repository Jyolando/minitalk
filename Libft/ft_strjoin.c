/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:30:33 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/07 22:30:33 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 || *s2)
	{
		if (*s1)
			str[i] = *(s1)++;
		else
			str[i] = *(s2)++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
