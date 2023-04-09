/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:23 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(char **word)
{
	int	word_len;
	int	atoi_error;

	word_len = count_strs(word);
	atoi_error = 0;
	printf("exit\n");
	if (*(word + 1) != NULL)
		g_status = ft_atoi(*(word + 1), &atoi_error);
	if (atoi_error == 1)
	{
		error(*(word + 1), NOT_NUMERIC_ERROR);
		exit(g_status);
	}
	if (word_len > 2)
	{
		error("exit", ARGUMENTS_CNT_ERROR);
		return ;
	}
	exit(g_status);
}
