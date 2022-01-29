/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:35:41 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/13 16:50:22 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp2 = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = tmp2;
		}
		*lst = NULL;
	}
}
