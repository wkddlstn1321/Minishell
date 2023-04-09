/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clip_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:42 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_clip_split(char **str, int *nbrs)
{
	int		idx;
	int		jdx;
	char	**new_split;

	idx = nbrs[0];
	jdx = 0;
	new_split = malloc(sizeof(char *) * (nbrs[1] - nbrs[0] + 1));
	if (new_split == NULL)
		return (NULL);
	while (idx < nbrs[1])
	{
		new_split[jdx++] = ft_strdup(str[idx++]);
		if (new_split[jdx - 1] == NULL)
			return (free_strs(new_split));
	}
	new_split[jdx] = NULL;
	return (new_split);
}
