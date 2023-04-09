/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:27 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:12:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *substr, int n)
{
	int			i;
	int			j;

	i = 0;
	if (*substr == 0)
	{
		return ((char *)str);
	}
	while (str[i] != 0 && i < n)
	{
		j = 0;
		while (str[i + j] == substr[j] && i + j < n)
		{
			j++;
			if (substr[j] == 0)
			{
				return ((char *)&str[i]);
			}
		}	
		i++;
	}
	return (0);
}
