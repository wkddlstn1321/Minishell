/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:11:54 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:54 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (dest[len] && len < size)
		len++;
	if (len == size)
		return (len + (size_t)ft_strlen((char *)src));
	return (len + ft_strlcpy(dest + len, src, size - len));
}
