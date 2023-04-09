NAME = minishell

SRCS = minishell.c\
		validate/validate_line.c validate/validate_syntax.c validate/check_redir_pipe.c\
		set/set_signal.c set/set_terminal_attr.c set/set_redir_lst.c set/set_word.c set/set_signal_term.c set/set_fd_default.c\
		utils/join_quotes.c utils/tokenizer.c utils/ft_free_lst.c utils/update_ev.c utils/convert_tilde.c utils/ascii_to_non_ascii.c utils/heredoc_utils.c\
		init/init_neat_line.c init/init_cmd_lst.c init/init_built_in.c\
		get/get_type_idx.c get/get_end_sig.c get/get_infile_fd.c get/get_heredoc.c get/get_outfile_fd.c get/get_forked_child.c\
		execute/execute_cmd.c execute/child_proc.c execute/exec_parent_built.c\
		builtin/export.c builtin/ft_exit.c builtin/env.c builtin/unset.c builtin/pwd.c builtin/echo.c\
		builtin/init_sorted_lst.c builtin/add_ev.c builtin/cd.c builtin/cd_home.c builtin/set_pwd.c builtin/exec_chdir.c builtin/cd_old_path.c\
		ev/get_value.c ev/get_key.c ev/convert_to_ev.c ev/add_ev_lst.c ev/create_ev_lst.c\
		ev/init_ev_lst.c  ev/get_ev_value.c ev/get_ev.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm
RMFLAGS = -rf
#LDFLAGS= -L/Users/hyunjung/.brew/opt/readline/lib
#CPPFLAGS= -I/Users/hyunjung/.brew/opt/readline/include

LDFLAGS= -L/opt/homebrew/opt/readline/lib
CPPFLAGS= -I/opt/homebrew/opt/readline/include

LIBFT_DIR = libft
LIBFT = ft
all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $ $^ -o $@ -lreadline -L$(LIBFT_DIR) -l$(LIBFT) $(LDFLAGS)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@

.PHONY : all clean fclean re
