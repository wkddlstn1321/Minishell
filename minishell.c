/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insjang <insjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/26 21:11:10 by insjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

int	print_exit(void)
{
	printf("\033[1A");
	printf("\033[11C");
	printf("exit\n");
	exit(g_status);
}

char	**parser(t_ev_lst	*ev_lst)
{
	char	**split_line;
	char	*neat_line;
	char	*line;

	neat_line = NULL;
	split_line = NULL;
	line = readline("minishell$ ");
	if (line == NULL)
		print_exit();
	if (line != NULL && validate_line(line) == 0)
	{
		neat_line = init_neat_line(line, ev_lst);
		if (neat_line == NULL)
			return (NULL);
		split_line = ft_split(neat_line, ' ');
		convert_tilde(split_line, ev_lst);
	}
	add_history(line);
	free(line);
	free(neat_line);
	return (split_line);
}

void	executer(char	**split_line, t_ev_lst	**ev_lst, char	**curr_path)
{
	t_cmd_lst	*cmd_lst;
	int			built_status;
	int			*tokens;

	tokens = tokenizer(split_line);
	if (tokens == NULL)
		return ;
	cmd_lst = init_cmd_lst(split_line, tokens);
	if (cmd_lst == NULL)
		return ;
	built_status = is_parent_built(cmd_lst);
	if (built_status != 0)
		exec_parent_built(built_status, cmd_lst, ev_lst, curr_path);
	else
		get_forked_child(cmd_lst, ev_lst, curr_path);
	free(tokens);
	ft_free_lst(cmd_lst);
}

int	main(int ac, char **av, char **ev)
{
	char		**split_line;
	char		*curr_path;
	t_ev_lst	*ev_lst;

	if (ac != 1 && av[1] != NULL)
		return (1);
	ev_lst = init_ev_lst(ev);
	curr_path = getcwd(NULL, 0);
	set_signal_term(SIG_DEF, ECHO_OFF);
	while (1)
	{
		split_line = NULL;
		split_line = parser(ev_lst);
		if (split_line != NULL)
		{
			if (*split_line != NULL && validate_syntax(split_line) == 0)
				executer(split_line, &ev_lst, &curr_path);
			ft_free_split(split_line);
		}
	}
	exit(0);
}
