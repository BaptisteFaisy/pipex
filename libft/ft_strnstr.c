/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:33:49 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/09 09:15:02 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	cur1;
	size_t	cur2;
	size_t	needle_len;

	if ((s1 == NULL && s2 != NULL && len == 0)
		|| (s1 != NULL && s2 == NULL && len == 0))
		return (0);
	if (!s1 && !s2 && len == 0)
		return (NULL);
	if (!s2[0])
		return ((char *)s1);
	cur1 = 0;
	needle_len = ft_strlen(s2);
	while (s1[cur1] && (cur1 + needle_len - 1) < len)
	{
		cur2 = 0;
		while (s2[cur2] && s1[cur1 + cur2] == s2[cur2])
		{
			if (cur2 == needle_len - 1)
				return ((char *)(s1 + cur1));
			cur2++;
		}
		cur1++;
	}
	return (0);
}

// int main()
// {
// 	char s1[] = "tetetestr";
// 	char s2[] = "es";
// 	printf("%s",ft_strnstr(s1, s2, 10));
// }