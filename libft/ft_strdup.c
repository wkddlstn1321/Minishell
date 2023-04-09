/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:11:40 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	int		i;
	char	*d;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	d = malloc(sizeof(char) * len + 1);
	if (!d)
	{
		error(NULL, 0);
		return (NULL);
	}
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
