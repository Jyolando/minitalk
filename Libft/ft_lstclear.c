/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:18:41 by jyolando          #+#    #+#             */
/*   Updated: 2021/10/05 23:50:04 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*plst;

	while (*lst)
	{
		plst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = plst;
	}
	*lst = NULL;
}
