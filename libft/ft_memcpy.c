/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:56:44 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 08:51:44 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;
	char	*dst_data;
	char	*src_data;

	if (!src && !dst)
		return (NULL);
	cur = 0;
	dst_data = (char *)dst;
	src_data = (char *)src;
	while (cur < n)
	{
		dst_data[cur] = src_data[cur];
		cur++;
	}
	return (dst_data);
}

/* int main()
{
	char *destination;
	destination = malloc(sizeof(char) * 8);
	char src[] = "test 1";
	printf("%s",ft_memcpy(destination, src,5 );
} */