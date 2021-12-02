/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:27:46 by jyolando          #+#    #+#             */
/*   Updated: 2021/10/03 10:50:35 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
