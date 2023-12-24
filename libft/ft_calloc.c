/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:05:17 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 17:54:22 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if ((unsigned int )count == 4294967295 && (unsigned int)size == 4294967295)
		return (NULL);
	if ((((unsigned)count != count && size != 0)
			|| ((unsigned)size != size && count != 0)))
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*((unsigned char *) ptr + i) = 0;
		i++;
	}
	return (ptr);
}
