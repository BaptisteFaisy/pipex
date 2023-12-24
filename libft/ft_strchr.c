/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:54:41 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 08:52:46 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cur;

	cur = 0;
	while (s[cur])
	{
		if (s[cur] == (unsigned char)c)
			return ((char *)(s + cur));
		cur++;
	}
	if (s[cur] == (unsigned char)c)
		return ((char *)(s + cur));
	return (0);
}

/* int main()
{
	char chaine[] = "tets1234";
	printf( "%s",ft_strchr(chaine, '1'));
} */