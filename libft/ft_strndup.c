/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:23 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:12:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	word_len;

	if (s == NULL)
		return (NULL);
	mem = malloc(len + 1);
	if (!mem)
	{
		error(NULL, 0);
		return (NULL);
	}
	i = 0;
	word_len = 0;
	mem[len] = '\0';
	while (word_len < len)
	{
		if (s[i] != '\'' && s[i] != '\"')
		{
			mem[word_len] = s[i];
			word_len++;
		}
		i++;
	}
	return (mem);
}
