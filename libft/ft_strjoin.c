/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:11:45 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:45 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*mem;

	if (!s1 || !s2)
	{
		free(s2);
		free(s1);
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * len_s1 + len_s2 + 1);
	if (mem != NULL)
	{
		ft_strlcpy(mem, s1, len_s1 + 1);
		ft_strlcat(mem, s2, len_s1 + len_s2 + 1);
	}
	else
		error(NULL, 0);
	free(s1);
	free(s2);
	return (mem);
}
