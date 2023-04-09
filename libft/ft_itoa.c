/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:11:03 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_length(int n)
{
	int	length;

	if (n == 0)
	{
		return (1);
	}
	length = 0;
	if (n < 0)
	{
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	long	value;
	int		length;
	char	*new_str;

	length = ft_int_length(n);
	value = n;
	new_str = malloc(length * sizeof(char) + 1);
	if (new_str == 0)
		return (0);
	if (value < 0)
	{
		new_str[0] = '-';
		value *= -1;
	}
	if (value == 0)
		new_str[0] = '0';
	new_str[length] = 0;
	length -= 1;
	while (value != 0)
	{
		new_str[length] = '0' + value % 10;
		length--;
		value /= 10;
	}
	return (new_str);
}
