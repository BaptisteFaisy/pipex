/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:30:15 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/08 11:09:50 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	cur;

	cur = -1;
	while (set[++cur])
		if (set[cur] == c)
			return (1);
	return (0);
}

static char	*empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (is_in_set(s1[start], set))
		start++;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	if (start == s1_len)
		return (empty_string());
	while (is_in_set(s1[end], set))
		end--;
	trim = malloc((end - start + 2) * sizeof(char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, (s1 + start), (end - start + 2));
	return (trim);
}

// int main()
// {
// 	printf("%s", ft_strtrim("okbbbfddstjk", "tok"));
// }