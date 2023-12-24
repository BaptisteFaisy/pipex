/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:11:24 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/07 08:28:55 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c )
{
	if ((unsigned char)c <= 122 && (unsigned char)c >= 97)
	{
		c = (unsigned char)c - 32;
	}
	return (c);
}
// int main()
// {
// 	printf("%c",ft_toupper('c'));
// }