/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:34 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:35 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	set_atoi_error(int *error)
{
	*error = 1;
	return (255);
}

static	int	skip_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	return (i);
}

int	check_minus(char c, int *minus)
{
	int	i;

	i = 0;
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*minus = -1;
		i++;
	}
	return (i);
}

unsigned char	ft_atoi(const char *str, int *error)
{
	unsigned long	atoi;
	int				minus;

	atoi = 0;
	minus = 0;
	if (str == NULL)
		return (0);
	str += skip_space(str);
	if (ft_strlen(str) > 1)
		str += check_minus(*str, &minus);
	while ('0' <= *str && *str <= '9')
	{
		atoi = (atoi * 10) + *str - '0';
		str++;
		if (atoi + minus > 9223372036854775807 && atoi != 0)
			return (set_atoi_error(error));
	}
	if (*str != '\0')
		return (set_atoi_error(error));
	if (minus == 0)
		return (atoi);
	return (atoi * minus);
}
