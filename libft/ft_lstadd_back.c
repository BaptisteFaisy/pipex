/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:26:15 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 15:44:26 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ratp;

	if (!lst)
		return ;
	if (*lst)
	{
		ratp = *lst;
		while (ratp->next)
			ratp = (ratp)->next;
		(ratp)->next = new;
	}
	else
		*lst = new;
}
