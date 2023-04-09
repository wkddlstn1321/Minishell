/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:15:59 by hyna              #+#    #+#             */
/*   Updated: 2022/09/01 14:11:25 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cntword(const char *s, char c)
{
	size_t			cnt;
	unsigned char	flag;
	char			**mem;

	cnt = 0;
	flag = 1;
	while (*s)
	{
		if (*s != c && flag == 1)
		{
			cnt++;
			flag = 0;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	mem = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!mem)
		return (NULL);
	ft_memset(mem, '0', sizeof(char *) * (cnt + 1));
	mem[cnt] = NULL;
	return (mem);
}

size_t	ft_wordlen(const char *s, char c, size_t *total_len)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		if (*s != '\'' && *s != '\"')
			len++;
		(*total_len)++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**mem;
	char	**cpy_mem;
	size_t	word_len;
	size_t	total_len;

	if (!s)
		return (NULL);
	mem = ft_cntword(s, c);
	if (!mem)
		return (NULL);
	cpy_mem = mem;
	while (*cpy_mem)
	{
		while (*s && *s == c)
			s++;
		total_len = 0;
		word_len = ft_wordlen(s, c, &total_len);
		*cpy_mem = ft_strndup(s, word_len);
		if (!*cpy_mem)
			return (ft_free_split(mem));
		s += total_len;
		cpy_mem++;
	}
	return (mem);
}
