/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:50 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_split(char **mem)
{
	int		idx;

	idx = 0;
	if (mem == NULL)
		return (NULL);
	while (mem[idx])
		free(mem[idx++]);
	free(mem);
	return (NULL);
}
