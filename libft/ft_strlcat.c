/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:58:49 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/09 09:12:47 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cur;

	cur = 0;
	if ((dst == NULL && src != NULL && dstsize == 0)
		|| (dst != NULL && src == NULL && dstsize == 0))
		return (0);
	src_len = ft_strlen(dst);
	if (dstsize <= src_len)
		return (ft_strlen(src) + dstsize);
	while (src[cur] && (src_len + cur) < (dstsize - 1))
	{
		dst[src_len + cur] = src[cur];
		cur++;
	}
	dst[src_len + cur] = 0;
	return (ft_strlen(src) + src_len);
}
