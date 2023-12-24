/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:12:11 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 09:22:46 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	return (join);
}

// int main()
// {
// 	char s1[] = "ok";
// 	char s2[] = "ngh";
// 	printf("%s", ft_strjoin(s1, s2));
// }