/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:25 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:13:25 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	sig_handler_def(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 1;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	sig_handler_ignore(int sig)
{
	if (sig == SIGINT)
		printf("\n");
	else if (sig == SIGQUIT)
		printf("Quit: %d\n", sig);
}

int	set_signal(int opt)
{
	if (opt == SIG_DEF)
	{
		if (signal(SIGINT, sig_handler_def) == SIG_ERR
			|| signal(SIGQUIT, sig_handler_def) == SIG_ERR)
			return (1);
	}
	else if (opt == SIG_DUP)
	{
		if (signal(SIGINT, SIG_DFL) == SIG_ERR
			|| signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			return (1);
	}
	else if (opt == SIG_IGNORE)
	{
		if (signal(SIGINT, sig_handler_ignore) == SIG_ERR
			|| signal(SIGQUIT, sig_handler_ignore) == SIG_ERR)
			return (1);
	}
	return (0);
}
