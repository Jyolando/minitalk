/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 23:19:01 by jyolando          #+#    #+#             */
/*   Updated: 2021/07/09 23:19:01 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	index;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	index = 0;
	while (ft_check_char(s1[index], set))
		index++;
	start = index;
	if (!s1[start])
	{
		newstr = (char *)malloc(1);
		if (newstr == NULL)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	while (s1[index + 1])
		index++;
	while (ft_check_char(s1[index], set))
		index--;
	newstr = ft_substr(s1, start, index - start + 1);
	return (newstr);
}
