/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:44:07 by jyolando          #+#    #+#             */
/*   Updated: 2021/10/04 20:54:28 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_word = 0;
		else if (s[i] != c && !is_word)
		{
			count++;
			is_word = 1;
		}
		i++;
	}
	return (count);
}

static char	*split_strdup(char const *s, int start, int end)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

char	**split_to_strings(char const *s, char c)
{
	char	**strings;
	size_t	curword;
	int		start;
	int		end;

	strings = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	curword = 0;
	end = 0;
	start = -1;
	while ((size_t)end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || (size_t)end == ft_strlen(s)) && start >= 0)
		{
			strings[curword++] = split_strdup(s, start, end);
			start = -1;
		}
		end++;
	}
	strings[curword] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = split_to_strings(s, c);
	if (!strings)
		return (NULL);
	return (strings);
}
