

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:29:09 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/15 20:12:50 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
//# include <readline/readline.h>
//# include <readline/history.h>
//# include <stdio.h>
# include <fcntl.h>
//# include <ios.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/stat.h>
//# include <dir.h>
# include <stdint.h>
# include <stdio.h>
//# include "dash/env.h"

# define PROMT "<3 "
# define PIPE '|'
# define SPACE " "

# define FIRST_ELEM 1
# define MIDDLE_ELEM 2
# define LAST_ELEM 3

# define FROM_FILE 11
# define TO_FILE 22
# define APPEND 33
# define HEREDOC 44
# define FF 999

// int	g_exit_status;

typedef struct t_env
{
	struct t_env		*next;
	char				*val;
	int					ind;
}t_env;

typedef struct s_redirect
{
	char	**args;//pipe_args[i]
	char	**exec_path;//exec_pipe[i]
	int		type;
	char	*file;

}t_redirect;

typedef struct s_data
{
	int				ex;
	int				in;
	int				out;
	t_env			*env1;
	char			**env;
	int				flag;
}t_data;

typedef struct s_cmd
{
	char			**env;
	char			*paths;
	char			**cmd_paths;//массив путей
	int				p;//cmd->p - это количество путей в path
	char			*str;//изначальная строка
	int				is_pipe;
	int				n;
	char			***pipe_args;
	char			**exec_pipe;
	struct t_env	*c_list;
	struct t_env	*c_list1;
	char			*s_q;
	struct t_env	*exec_list;
	struct t_env	*pipes;
	// int				fd[2];
	int				error;
	int				exitstatus;//check_exitstatus
	char			*file;
	int				r;
	t_redirect		**redirect;
}t_cmd;



//main.c
char	**massiv2(t_env *list);

//envinit.c

int		env_len(char **env);
t_env	*new_list(char *s, int n);
void	add_list(t_env *e, t_env *new);
t_env	*init_env(t_data *d, char **env);
void	rl_replace_line(const char *text, int clear_undo);
void	sighand(int sig);
int		ft_strcmp(char *s1, char *s2);
int		pwd(t_data *d);
void	env(t_data *d);
int		ctoi(char *s);
char	*ft_itoa(int n);
void	sh_lvl(char **env);
int		stacklen(t_env	*c_list);
int		check_char(char c);
void	del_first(t_env **c);
//cmd.c
char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
t_cmd	*init_cmd(char **envp);

//parse.c
int		parse_cmd(t_cmd *cmd);
//int		qparse_cmd(t_cmd *cmd);
int		qparse_cmd(t_cmd *cmd, t_data *d);
int		is_pipe(t_cmd *cmd);
int		is_cmd(t_cmd *cmd, struct t_env *c_list);
int		exec_simple(t_cmd *cmd, struct t_env *c_list, t_data *data);
int		check_exitstaus(pid_t pid, t_cmd *cmd);
char	**put_args_together(t_cmd *cmd, struct t_env *c_list);
void	parse_redirect(t_cmd *cmd, struct t_env *c_list);
int		find_file(t_cmd *cmd);
int		find_cmd(char **paths, char *s);
void	set_redirect_index(t_cmd *cmd);

// redirect.c
void set_redirect(t_cmd *cmd, struct t_env *c_list, int *fd);

//executor.c
pid_t	*init_pid(t_cmd *cmd);
int	redirect_fd(int *fd, int flag, pid_t *pid, int *close_fd);
void	exec_multi_pipe(t_cmd *cmd);
pid_t	exec_pipe_command(t_cmd *cmd, char *cmd_path, int i, int close_fd);
int exec_single_pipe(t_cmd *cmd);

//pipes.c
// int execute_pipes(t_cmd *cmd, t_data *data);

//pipexator.c
void	execute_pipes(t_cmd *cmd, t_data *data);

//ft_split.c
size_t	ft_count_words(char const *s, char c);
char	**ft_split(char const *s, char c);

//isspace.c
int	is_all_spaces(char *s);
char *del_extra_space(char *s);

//libft/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_calloc(size_t n, size_t size);

// int		ft_isspace(char *s, int i);
int		qcheck_q(t_cmd *cmd, int i);
int		check_q(t_cmd *cmd);
//int		check_qq(t_cmd *cmd);
char	*ft_strdup(const char *s1);
void	open_q(t_cmd *cmd);
//char	*ft_strtrim(char const *s1, char const *set);
int		check_close(char *s);
int		ft_cd(char *s, t_cmd *cmd, t_data *d);
int		check_sep(t_env *c);
void	trash(int argc, char **argv);
void	signals1(void);
void	signals2(void);
int		check_syn(char *s);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_atoi(const char *str);
void	ft_exit(char **a, t_data *d, t_cmd *cmd);
void	*ft_1free(char **s);
void	ft_free(t_cmd *cmd, t_data *d);
void	ft_free_list(t_env *a, void (*del)(void *));
void	unset_one(char *s, t_data *d);
char	*open_qo(char *s);
char	*open_s(char *s, t_cmd *cmd, t_data *d);
char	*open_s1(char *s, t_cmd *cmd, t_data *d, t_env *a);
int		check_s(char *s);
int		indexq(char c);
t_env	*open_dd(int (*i), char *s);
void	open_dd1(int (*i), int (*x), char *s);
void	open_dd2(int (*i), int (*x), char *s);
void	open_dd3(int (*i), int (*x), char *s);
void	open_dd4(int (*i), int (*x), char *s, t_env **a);
void	open_dd5(int (*i), int (*x), char *s, t_env **a);
int		qtoklen(char *s, int i);
int		toklen2(char *s, int i);
int		toks(char c, char a);
int		qoutee(char *s);
int		count1(char *s);
int		ft_strncmp_env(const char *s1, const char *s2, size_t n);
char	*open_d(char *s, t_cmd *cmd, t_data *d);
int		check_char(char c);
char	*findenv(char *s, t_data *d, t_cmd *cmd);

#endif