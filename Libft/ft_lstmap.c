/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:05:53 by jyolando          #+#    #+#             */
/*   Updated: 2021/10/04 15:15:47 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*ready;

	ready = NULL;
	while (lst)
	{
		temp_lst = ft_lstnew(f(lst->content));
		if (!temp_lst)
		{
			ft_lstclear(&temp_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ready, temp_lst);
		lst = lst->next;
	}
	return (ready);
}
