/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:11:01 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 08:50:45 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	cur;
	char	*data;

	cur = 0;
	data = (char *)b;
	while (cur < len)
	{
		data[cur] = c;
		cur++;
	}
	return (b);
}

// int main()
// {
// 	char s[] = "test";
// 	// in = malloc(sizeof(size_t)* 5);
// 	ft_memset(s, 0, 5);
// // while (i != 5)
// // 		printf("%d", in[i++]);	
// }