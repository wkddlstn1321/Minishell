/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:59 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:59 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_lst(char **lst)
{
	int	i;

	i = 0;
	while (i < 7)
		free(lst[i++]);
	free(lst);
}

static int	validate_built_in(char **lst)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (lst[i++] == NULL)
		{
			free_lst(lst);
			return (-1);
		}
	}
	return (0);
}

char	**init_build_in(void)
{
	char	**lst;
	int		i;

	i = 0;
	lst = malloc(sizeof(char *) * 8);
	lst[i++] = ft_strdup("echo");
	lst[i++] = ft_strdup("cd");
	lst[i++] = ft_strdup("pwd");
	lst[i++] = ft_strdup("export");
	lst[i++] = ft_strdup("unset");
	lst[i++] = ft_strdup("env");
	lst[i++] = ft_strdup("exit");
	lst[i++] = NULL;
	if (validate_built_in(lst))
	{
		error(NULL, 0);
		return (NULL);
	}
	return (lst);
}
