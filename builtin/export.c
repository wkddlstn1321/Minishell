/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_all_ev(t_ev_lst *ev_lst)
{
	t_ev_lst	*tmp;
	t_ev_lst	*sorted_lst;
	char		*dup_value;

	sorted_lst = init_sorted_lst(ev_lst);
	while (sorted_lst != NULL)
	{
		dup_value = ft_strdup(sorted_lst->value);
		if (dup_value == NULL)
		{
			error(NULL, 0);
			return ;
		}
		to_ascii(dup_value);
		printf("declare -x %s", sorted_lst->key);
		if (sorted_lst->equal_sign == 1)
			printf("=\"%s\"", dup_value);
		printf("\n");
		tmp = sorted_lst;
		sorted_lst = sorted_lst->next;
		free(dup_value);
		free(tmp);
	}
}

int	export(t_cmd_lst *cmd_lst, t_ev_lst *ev_lst)
{
	int		idx;
	char	**word;

	g_status = 0;
	word = (cmd_lst->word + 1);
	idx = 0;
	if (word[idx] == NULL)
		print_all_ev(ev_lst);
	while (word[idx] != NULL)
	{
		g_status |= add_ev(word[idx], ev_lst);
		idx++;
	}
	return (0);
}
