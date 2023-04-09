/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insjang <insjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:14:17 by hyna              #+#    #+#             */
/*   Updated: 2022/12/26 21:18:07 by insjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	creat_redir_lst(t_cmd_lst *cmd_lst)
{
	int			*tokens;
	int			nbrs[2];

	nbrs[START_IDX] = 0;
	nbrs[END_IDX] = 0;
	tokens = tokenizer(cmd_lst->word);
	set_redir_lst(cmd_lst, tokens, nbrs);
	set_word(cmd_lst, tokens);
	free(tokens);
	return (0);
}

t_cmd_lst	*add_new_cmd(char **split_str, int	*nbrs)
{
	t_cmd_lst	*cmd_lst;
	char		**new_str;

	new_str = ft_clip_split(split_str, nbrs);
	cmd_lst = malloc(sizeof(t_cmd_lst));
	if (!cmd_lst)
	{
		error(NULL, 0);
		return (NULL);
	}
	cmd_lst->word = new_str;
	cmd_lst->redir_lst = NULL;
	if (creat_redir_lst(cmd_lst))
		return (NULL);
	cmd_lst->next = NULL;
	return (cmd_lst);
}

t_cmd_lst	*init_cmd_lst(char **split_str, int *tokens)
{
	t_cmd_lst	*cmd_lst;
	t_cmd_lst	*cur;
	int			nbrs[2];

	cmd_lst = NULL;
	cur = NULL;
	nbrs[START_IDX] = 0;
	nbrs[END_IDX] = 0;
	while (tokens[nbrs[END_IDX]] != IS_END)
	{
		nbrs[END_IDX] = get_type_idx(tokens, nbrs[START_IDX], IS_PIPE);
		if (cur == NULL)
			cur = add_new_cmd(split_str, nbrs);
		else
		{
			cur->next = add_new_cmd(split_str, nbrs);
			cur = cur->next;
		}
		if (cur == NULL)
			return (NULL);
		if (cmd_lst == NULL)
			cmd_lst = cur;
		nbrs[START_IDX] = nbrs[END_IDX] + 1;
	}
	return (cmd_lst);
}
