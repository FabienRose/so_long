/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:49 by fmixtur           #+#    #+#             */
/*   Updated: 2024/12/02 16:32:30 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todelete;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		todelete = *lst;
		*lst = todelete->next;
		ft_lstdelone(todelete, del);
	}
}
