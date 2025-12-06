/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:50:47 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 02:53:48 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/utsname.h>
# include <pwd.h>
# include <unistd.h>
# include <termios.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft/libft.h"

typedef struct s_del
{
	char			*limit;
	struct s_del	*next;
}	t_del;

typedef struct s_hdoc
{
	char			*filename;
	int				fd;
	int				here_cnt;
	t_del			*del;
	t_del			*del_head;
	struct s_hdoc	*next;
}	t_hdoc;

typedef struct s_comm
{
	char			*token;
	int				length;
	int				type;
	struct s_comm	*next;
}	t_comm;

typedef struct s_envp
{
	char			*key;
	char			*value;
	int				state;
	struct s_envp	*next;
}	t_envp;

typedef struct s_env_d
{
	t_envp		*data;
	t_envp		*head;
	t_envp		*tail;
}	t_env_d;

typedef struct s_data
{
	char			**args;
	int				in_fd;
	int				out_fd;
	int				arg_cnt;
	int				cnt_heredoc;
	int				cmd_count;
	int				i_pid;
	pid_t			*pid;
	struct s_data	*next;
}	t_data;

typedef struct s_range
{
	int	start;
	int	i;
}	t_range;

# define STR 0
# define PIPE 1
# define DLESS 2 // <<
# define LESS 3 // <
# define DGREAT 4 // >>
# define GREAT 5 // >

# define HAS_EQUAL 10 // envp_state
# define NO_EQUAL 11

// need define num change
# define REMOVE 6
# define LEAVE 7
# define QUOTED 8
# define UNQUOTED 9
# define CONTINUE 10
# define SINGLE 11
# define DOUBLE 12

# define SYNTAX_ERR 258

/* signal.c */

int		g_signal;

void	ctl_print_off(void);
void	handler_sigint(int key);
void	handler_sig_child(int key);
void	handler_sigquit(int key);

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

char	**put_args(char **args, char *token, int cnt);
char	**make_args(t_comm *com, int *args_cnt);

int		exe_cmd(t_comm *cmd, t_env_d *my_envp, char **args, int args_cnt);
int		is_blt(char **args);

t_env_d	*make_envp(char **envp);

int		ft_redirect_handling(t_comm *cmd, t_hdoc *hdoc);
int		exe_redirection(t_comm *cmd, t_hdoc *hdoc);

void	run_command(t_comm *cmd, t_env_d *my_envp_d, t_data *ofd_arg);
void	free_ofd_args(t_data **ofd_arg);

char	**make_args_fork(t_comm *cmd, int *args_cnt);
void	child_process(t_comm *cmd, t_env_d *my_envp_d, \
	t_data *ofd_arg, t_hdoc *hdoc);
t_comm	*move_cmd(t_comm *cmd);

/* heredoc */
int		is_more_heredoc(t_comm *cmd);
t_hdoc	*in_hdoc(t_comm *cmd, t_hdoc *hdoc, char *tmp);
t_hdoc	*set_hdoc(void);
int		is_heredoc(t_comm *cmd);
int		ft_here_document(t_hdoc *hdoc);
t_hdoc	*ft_heredoc(t_comm *cmd);
char	*set_file_name(void);
int		is_delimiter(char *input, char *delimiter);
void	more_heredoc(t_hdoc **hdoc, char **tmp);
t_hdoc	*make_hdoc(t_comm *cmd, t_hdoc *hdoc);

/* about_fork.c */
void	use_fork(t_comm *cmd, t_env_d *my_envp, t_data *ofd_arg, t_hdoc *hdoc);
void	not_fork(t_comm *cmd, t_env_d *my_envp, t_data *ofd_arg, t_hdoc *hdoc);

/* builtin */
void	ft_pwd(void);
int		ft_cd(char **args, t_env_d *my_envp);
void	ft_echo(char **args, t_env_d *my_envp);
void	ft_export(t_env_d *my_envp, char **args, int args_cnt);
void	ft_unset(t_env_d *my_envp, char **args);
void	ft_env(t_env_d *my_envp);
void	ft_exit(t_comm *cmd, char **args);
int		ft_execve(char **args, t_envp *my_envp);
void	add_export(t_envp *my_envp, char **args, int i_line);
void	modi_export(t_envp *my_envp, char **args, int i_line, int pos);
void	list_export(t_envp *my_envp);

char	**make_origin_envp(t_envp *my_envp);

void	add_envp(t_envp *my_envp, char **envp, int i_line);

char	*find_cmd_path(char *command, t_envp *my_envp);

void	update_recent_exit_status(t_env_d *my_envp_d, int sign);

/* free.c */
void	free_ofd_args(t_data **ofd_arg);
void	free_envp(t_env_d *my_env_d);
void	free_all_hdoc(t_hdoc **hdoc);

/* main_utils */
t_data	*allocate_ofd_arg(t_data *ofd_arg);
void	control_arg(int argc, char **argv);

/* tokenizing */

/* tokenize.c */

char	*mk_strdup(int start, int end, char *line, int flag);
void	split_line(char *line, t_comm **cmd, t_env_d *envp);

/* put_on_list.c */
int		prev_check(t_comm **cmd, char *token, int type);
void	push_back(t_comm **cmd, char *token, int type);

/* find syn_err.c */
int		find_syntax_err(char *buf, t_env_d *envp);
int		pipe_at_the_end(char *buf);

/* pre_processing.c */
int		tokenizing(char *line, t_comm **cmd, t_env_d *envp);
int		read_input(t_comm **cmd, t_env_d *envp);
void	free_list(t_comm **cmd);

/* token_utils.c */
int		is_del(char *line);
int		is_space(char a);
int		is_dquotes(char a);
int		is_squotes(char a);
int		is_redirect(char a);

/* token_utils_two.c */
int		is_pipe(char a);
int		is_env(char a);
t_range	*allocate_range(int index, int start);

/* process_delimited.c */
char	*find_del(char *token, t_comm **cmd, int start, t_env_d *envp);
void	push_back_delimited(char *token, int *index, t_comm **cmd, int *start);
void	distinguishing_redirec(char *new_token, int flag, t_comm **cmd);
void	process_prev_str(char *token, t_range *range, \
	t_comm **cmd, t_env_d *envp);

/* search_dollar_env.c */
int		check_dless(t_comm *cmd);
char	*search_env_name(char *str);
int		return_last_dollar_pos(char *str);
char	*find_last_dollar(char *str);
void	find_last_pos(char **str);

/* process_remove.c */
void	split_env(char **token, t_comm **cmd);
void	remove_dollar(char *str);
void	remove_undefined_env(char **token);
void	remove_quotes(char **str, int start);

/* process_dollar.c */
void	connecting_string(char **token, char *var_value, \
	char *var_name, char *dollar_pos);
void	processing_after_dless(char **token);
void	put_in_env(char **token, char **dollar_pos, \
	t_env_d *envp, t_comm **cmd);
int		process_env_var(char **token, t_comm **cmd, t_env_d *envp);

/* work_inside_quotes.c */
void	process_in_quotes(char *line, t_range *range, \
	t_comm **cmd, t_env_d *envp);
void	push_quote_string(t_comm **cmd, char *line, int index, char **temp);
char	*process_dquo(char *line, t_range *range, t_comm **cmd, t_env_d *envp);
char	*process_squo(char *line, t_range *range, t_comm **cmd, t_env_d *envp);

/* utils_quotes.c */
void	process_natural_str(char **temp, t_comm **cmd, t_env_d *envp);
void	index_update(int *i, int *start, int quote_pos);
void	free_temp(char **temp, char **quo_str);
void	free_var(char **var_value, char **var_name);

char	*ft_get_env(t_envp *envp, char *var_name);

#endif