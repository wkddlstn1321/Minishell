/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:06:53 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:06:53 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	check_option(char *word)
{
	int	option_flag;

	option_flag = 0;
	if (word != NULL && ft_strncmp(word, "-n", 2) == 0)
	{
		word += 2;
		while (*word == 'n')
			word++;
		if (*word == '\0')
			option_flag = 1;
	}
	return (option_flag);
}

void	echo(t_cmd_lst *cmd_lst)
{
	char	**word;
	int		option_flag;
	int		idx;

	option_flag = 0;
	word = cmd_lst->word + 1;
	idx = 0;
	while (check_option(word[idx]) == 1)
		idx++;
	if (idx != 0)
		option_flag = 1;
	while (word[idx] != NULL)
	{
		printf("%s", word[idx]);
		if (word[idx + 1] != NULL)
			printf(" ");
		idx++;
	}
	if (option_flag == 0)
		printf("\n");
	g_status = 0;
}
