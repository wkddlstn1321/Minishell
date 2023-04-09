/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:40 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:12:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char *set, char s1_c)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == s1_c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;
	size_t	idx;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	begin = 0;
	while (s1[begin] && find_set((char *)set, s1[begin]))
		begin++;
	end = ft_strlen(s1) - 1;
	while (end > begin && find_set((char *)set, s1[end]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - begin + 2));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (begin <= end)
		str[idx++] = s1[begin++];
	str[idx] = '\0';
	return (str);
}
