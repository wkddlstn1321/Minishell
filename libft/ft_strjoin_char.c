/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:11:50 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h"

char	*init_s2(char c)
{
	char	*s2;

	s2 = malloc(2);
	if (s2 == NULL)
		return (NULL);
	s2[0] = c;
	s2[1] = '\0';
	return (s2);
}

char	*ft_strjoin_char(char *s1, char c)
{
	unsigned int	len_s1;
	char			*mem;
	char			*s2;

	if (!s1)
		return (NULL);
	s2 = init_s2(c);
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	mem = (char *)malloc(sizeof(char) * (len_s1 + 2));
	if (mem != NULL)
	{
		ft_strlcpy(mem, s1, len_s1 + 1);
		ft_strlcat(mem, s2, len_s1 + 2);
	}
	else
		error(NULL, 0);
	free(s1);
	free(s2);
	return (mem);
}
