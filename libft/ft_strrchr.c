/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:36 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:12:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tmp;
	int		pos;

	pos = (int) ft_strlen(s);
	tmp = (char) c;
	while ((pos >= 0) && (s[pos] != tmp))
		pos--;
	if (pos == -1)
		return (NULL);
	return ((char *) &s[pos]);
}
