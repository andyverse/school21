#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ERRSYNTAX "minishell: syntax error near unexpected token\n"

typedef struct s_redir
{
	char			*stop;
	char			*name;
	int				frst;
	int				scnd;
	int				cmd;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	char			**cmd;
	int				build;
	t_redir			*in;
	t_redir			*out;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_env
{
	char			*sep;
	char			*name;
	char			*val;
	struct s_env	*next;
}					t_env;

typedef struct s_prm
{
	int		num;
	t_cmd	*cmd;
	char	**env;
	t_env	*envptr;
	t_redir	*redir;
	int		er_num;
	int		**fd;
}			t_prm;

void	ft_heredoc(char *name, char *stop, t_prm *prm);
void	ft_redir_to_cmd(t_redir *redir, t_cmd *cmd);
void	rl_replace_line(const char *buffer, int val);
int		ft_pre_open(t_prm *prm);
void	ft_do_pipe(t_prm *prm);
int		ft_cmd_counter(t_cmd *cmd);
void	ft_fd_close(t_prm *prm, int *fd, int num);
void	ft_child(int i, t_prm *prm);
void	ft_pipex(t_prm *prm);
void	ft_do_dup2(int i, int *fd, t_cmd *cmd, t_prm *prm);
void	ft_err_exit(int er_num, char *str, t_prm *prm);
int		ft_check_empty_str(char *str);
void	ft_env_list_arr(t_env *env_p, char ***env, t_prm *prm);
void	ft_data_add(int *i, char *str, t_prm *prm, int n);
char	*ft_dollar_check(char *str, int *i, t_env *env, t_prm *prm);
void	ft_free(char **tmp, char **tmp2, char **ch_dollar);
void	ft_cmd_clean(t_prm *prm);
char	*ft_cmd_bkslash1(char *str, int *i, t_prm *prm);
char	*ft_cmd_bkslash2(char *str, int *i, t_env *env, t_prm *prm);
char	*ft_dollar(char *str, int *i, t_env *env, t_prm *prm);
void	ft_parse_env(char **env, t_env **envp, t_prm *prm);
void	ft_bkslash1(char *str, int *i);
void	ft_bkslash2(char *str, int *i);
void	ft_struct_init(t_prm *prm);
t_cmd	*ft_creat_node(char *str, int *i, t_prm *prm);
void	ft_list_add(t_cmd **cmd, t_cmd *new);
char	*ft_itoa_minishell(int n, t_prm *prm);
int		ft_preparser(char *str);
void	ft_parsing(char *str, t_prm *prm);
void	ft_redirect(char *str, int *i);
void	ft_redir_add_back(t_redir **redir, t_redir *new);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup_mshell(const char *s1, t_prm *prm);
char	*ft_strjoin_mshell(char const *s1, char const *s2, t_prm *prm);
char	*ft_substr_mshell(char const *s, unsigned start, \
		size_t len, t_prm *prm);
void	ft_pipex_signal(int signal);
void	ft_child_signal(int signal);
void	ft_sig_handler(int sig);
int		ft_build_env(t_env *env);
int		ft_build_echo(t_cmd *cmd, t_prm *prm);
int		ft_build_pwd(t_prm *prm);
int		ft_build_cd(t_cmd *cmd, t_env *env, t_prm *prm);
int		ft_build_unset(t_cmd *cmd, t_prm *prm);
int		ft_build_export(t_cmd *cmd, t_prm *prm);
t_env	*ft_env_new(char *env, t_prm *prm);
t_env	*ft_env_find_tail(t_env *tail);
void	ft_env_add_last(t_env **env, t_env *new);
void	ft_check_shell_lvl(t_prm *prm);
void	ft_free_str(t_prm *prm, char *str);
int		ft_run_builds(t_cmd *cmd, t_prm *prm);
void	ft_builds_set(t_cmd *cmd);
void	ft_build_redup(int fd, t_prm *prm);
int		ft_build_dup(t_cmd *cmd, t_prm *prm);
int		ft_build_exit(t_cmd *cmd, t_prm *prm);

#endif
