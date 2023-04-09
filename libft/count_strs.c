/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:25 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strs(char	**strs)
{
	int	len;

	len = 0;
	if (strs == NULL)
		return (len);
	while (strs[len])
		len++;
	return (len);
}
