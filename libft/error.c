/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	usr_def_error1(char	*str, int error)
{
	ft_putstr_fd("minishell: ", 2);
	if (error == SYNTAX_ERROR)
	{
		g_status = 258;
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\'\n", 2);
	}
	else if (error == COMMAND_ERROR)
	{
		g_status = 127;
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (error == REDIR_ERROR)
	{
		g_status = 1;
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

static void	usr_def_error2(char	*str, int error)
{
	ft_putstr_fd("minishell: ", 2);
	if (error == ARGUMENTS_CNT_ERROR)
	{
		g_status = 1;
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": too many arguments\n", 2);
	}
	else if (error == KEY_ERROR)
	{
		g_status = 1;
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
	}
	else if (error == NOT_NUMERIC_ERROR)
	{
		g_status = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
}

static void	usr_def_error3(char	*str, int error)
{
	ft_putstr_fd("minishell: ", 2);
	if (error == UNCLOSED_QUOTES_ERROR)
	{
		g_status = 127;
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": quotes is unclosed\n", 2);
	}
	else if (error == SPECIAL_CHAR_ERROR)
	{
		g_status = 127;
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": unspecified special characters error\n", 2);
	}
	else if (error == ENVP_NONE_SET_ERROR)
	{
		g_status = 1;
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" not set\n", 2);
	}
}

static void	usr_def_error4(char	*str, int error)
{
	ft_putstr_fd("minishell: ", 2);
	if (error == CD_ERROR)
	{
		g_status = 1;
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

void	error(char	*str, int error)
{
	if (str)
	{
		if (error / 3 == 0)
			usr_def_error1(str, error);
		else if (error / 3 == 1)
			usr_def_error2(str, error);
		else if (error / 3 == 2)
			usr_def_error3(str, error);
		else if (error / 3 == 3)
			usr_def_error4(str, error);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}
