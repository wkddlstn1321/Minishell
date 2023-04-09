/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:45 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_strs_back(char	**dst, char **src)
{
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	while (dst[idx])
		idx++;
	while (src[jdx])
	{
		dst[idx] = ft_strdup(src[jdx]);
		if (dst[idx] == NULL)
		{
			ft_free_split(dst);
			return (1);
		}
		idx++;
		jdx++;
	}
	dst[idx] = NULL;
	return (0);
}

char	**ft_double_strjoin(char	**s1, char	**s2)
{
	char	**strs;

	if (s1 == NULL && s2)
		return (s2);
	else if (s2 == NULL && s1)
		return (s1);
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_strs(s1) + count_strs(s2) + 1));
	if (strs == NULL)
		return (NULL);
	strs[0] = NULL;
	if (add_strs_back(strs, s1))
		return (NULL);
	if (add_strs_back(strs, s2))
		return (NULL);
	ft_free_split(s1);
	ft_free_split(s2);
	return (strs);
}
