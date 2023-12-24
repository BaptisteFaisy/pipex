/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:03:25 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/09 08:31:41 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (del && lst)
	{
		tmp = *lst;
		while (tmp->next)
		{
			del(tmp->content);
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
		del(tmp->content);
		free(tmp);
		*lst = NULL;
	}
}
