/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:13:13 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// for readline function
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
// for free
# include <stdlib.h>
// for signal
# include <signal.h>
// terminal
# include <termios.h>
// write
# include <unistd.h>
// open
# include <fcntl.h>
// wait
# include <sys/wait.h>

# include <errno.h>

# include <string.h>

# include "libft/libft.h"
# include "libft/get_next_line.h"

extern int	g_status;

typedef struct s_redir_lst
{
	int					fd;
	char				*redir;
	char				*filename;
	struct s_redir_lst	*next;
}	t_redir_lst;

typedef struct s_cmd_lst
{
	char				**word;
	t_redir_lst			*redir_lst;
	struct s_cmd_lst	*next;
}	t_cmd_lst;

typedef struct s_ev_lst
{
	char				*key;
	char				*value;
	int					equal_sign;
	struct s_ev_lst		*next;
}	t_ev_lst;

typedef enum e_term_opt
{
	ECHO_OFF = 0,
	ECHO_ON = 1
}	t_term_opt;

typedef enum e_sig_opt
{
	SIG_DEF = 0,
	SIG_DUP = 1,
	SIG_IGNORE = 2
}	t_sig_opt;

typedef enum e_heredoc_info
{
	NONE = 0,
	SINGLE = 1,
	MULTIPLE = 2
}	t_heredoc_info;

typedef enum e_syntax_types
{
	IS_END = 0,
	IS_WORD = 1,
	IS_REDIR = 2,
	IS_PIPE = 3,
	IS_FILE = 4
}	t_syntax_types;

typedef enum e_built_types
{
	IS_ECHO = 0,
	IS_CD = 1,
	IS_PWD = 2,
	IS_EXPORT = 3,
	IS_UNSET = 4,
	IS_ENV = 5,
	IS_EXIT = 6
}	t_built_types;

typedef enum e_error_types
{
	SYNTAX_ERROR = 0,
	REDIR_ERROR,
	COMMAND_ERROR,
	KEY_ERROR,
	ARGUMENTS_CNT_ERROR,
	NOT_NUMERIC_ERROR,
	UNCLOSED_QUOTES_ERROR,
	SPECIAL_CHAR_ERROR,
	ENVP_NONE_SET_ERROR,
	CD_ERROR
}	t_error_types;

typedef enum e_nbrs_idx
{
	START_IDX = 0,
	END_IDX = 1
}	t_nbrs_idx;

typedef enum e_quotes_status
{
	QUOTES_OFF = 0,
	SINGLE_QUOTES_ON = 1,
	DOUBLE_QUOTES_ON = 2
}	t_quotes_status;

typedef enum e_converted_char
{
	SPACE_ = -1,
	PIPE = -2,
	IN_REDIR = -3,
	OUT_REDIR = -4,
	SINGLE_QUOTES = -5,
	DOUBLE_QUOTES = -6,
	TILDE = -7,
}	t_converted_char;

typedef enum e_char_type
{
	ENVP = 0,
	QUTOES = 1
}	t_char_type;

typedef enum e_proc_type
{
	CHILD = 0,
	PARENT = 1
}	t_proc_type;

/* set direcotry */
int			set_signal(int opt);
int			set_terminal_attr(int opt);
int			set_signal_term(int sig_opt, int term_opt);

int			validate_line(char *line);
char		*init_neat_line(char *line, t_ev_lst *ev_lst);
char		ascii_to_non_ascii(char c, t_char_type type,
				t_quotes_status status);
char		*join_quotes(char **line, char *neat_line, t_ev_lst *ev_lst);
char		*convert_to_ev(char **line, char *neat_line,
				t_ev_lst *ev_lst, t_quotes_status quotes_status);
int			check_redir_pipe(char *str);

/* syntax directory */
int			*ft_arrjoin(int *arr, int newnbr, int count);
int			*tokenizer(char **str);
int			validate_syntax(char **split_line);

/* heredoc dir */
char		*ft_join(char const *s1, char const *s2);
int			heredoc_single(t_redir_lst	*redir_lst);
int			heredoc_multiple(t_redir_lst *redir_lst);
int			get_infile_fd(t_redir_lst *redir_lst);
int			get_outfile_fd(t_redir_lst *redir_lst);
int			get_forked_child(t_cmd_lst *cmds,
				t_ev_lst **evl, char	**curr_path);
int			execute_cmd(t_cmd_lst *cmd_lst, char**ev);
int			child_proc(t_cmd_lst *cmd_lst,
				t_ev_lst **ev_lst, int	*redir_fd, char	**curr_path);
int			exec_parent_built(int built_idx, t_cmd_lst *cmd_lst,
				t_ev_lst **ev_lst, char	**curr_path);
int			is_parent_built(t_cmd_lst *lst);

/* init dir*/
t_ev_lst	*init_ev_lst(char **ev);
t_cmd_lst	*init_cmd_lst(char **split_str, int *tokens);
char		**init_build_in(void);

/* redir_setting */
int			make_fd_cur(t_cmd_lst *cmd_lst, int **fd_prev, int **fd_cur);

/* get directory */
int			get_type_idx(int	*tokens, int start_idx, int type);
int			get_heredoc(t_redir_lst *redir_lst);
char		*get_end_sig(t_redir_lst	*redir_lst);
char		*get_key(char *ev);
char		*get_value(char *ev, int *equal_sign);

/* set directory */
int			set_fd_default(int	*prev, int	*next, int	*old);
int			set_word(t_cmd_lst *cmd_lst, int *tokens);
int			set_redir_lst(t_cmd_lst *cmd_lst, int *tokens, int *nbrs);
void		to_ascii(char	*word);

/* utils directory */
char		*ft_free_lst(t_cmd_lst *cmd_lst);
char		**update_ev(t_ev_lst	*ev_lst);
void		convert_tilde(char **split_line, t_ev_lst *ev_lst);

//Built-in
int			export(t_cmd_lst *cmd_lst, t_ev_lst *ev_lst);
void		ft_exit(char **word);
void		env(t_cmd_lst *cmd_lst, t_ev_lst *ev_lst);
void		unset(t_cmd_lst *cmd_lst, t_ev_lst **ev_lst);
void		cd(t_cmd_lst *cmd_lst, t_ev_lst *ev_lst, char **curr_path);
void		pwd(char *curr_path);
int			add_ev(char *word, t_ev_lst *ev_lst);
void		add_ev_lst(t_ev_lst **ev_lst_head, t_ev_lst *new_lst);
t_ev_lst	*create_ev_lst(char *key, char *value, int equal_sign);
t_ev_lst	*init_sorted_lst(t_ev_lst *ev_lst);
void		echo(t_cmd_lst *cmd_lst);
void		cd_home(char *word, t_ev_lst *ev_lst, char **curr_path);
void		set_pwd(char *old_pwd, t_ev_lst *ev_lst, char **curr_path);
void		fail_cd(char *old_pwd, char *value);
void		exec_chdir(char *path, char *pwd,
				t_ev_lst *ev_list, char **curr_path);
void		cd_old_path(t_ev_lst *ev_lst, char **curr_path);

//test code
void		test_prin(char **mem);
void		print_structs(t_cmd_lst	*cmd_lst);

char		*get_ev_value(char *input, t_ev_lst *ev);
t_ev_lst	*get_ev(char *input, t_ev_lst *ev);
#endif
