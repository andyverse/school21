#include "minishell.h"

int	ft_prepars_1(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|')
		return (1);
	while (str[i])
	{
		if (str[i] == '|')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 0 || str[i] == '|')
			return (1);
		while (str[i] != 0 && str[i] != '|')
		{
			if (str[i] == '\'')
				ft_bkslash1(str, &i);
			else if (str[i] == '\"')
				ft_bkslash2(str, &i);
			else
				i++;
		}
	}
	return (0);
}

static void	ft_redirect_find(char *str, int *i)
{
	while (str[*i] && str[*i] != '<' && str[*i] != '>')
	{
		if (str[*i] == '\'')
			ft_bkslash1(str, i);
		else if (str[*i] == '\"')
			ft_bkslash2(str, i);
		else
			(*i)++;
	}
}

int	ft_prepars_2(char *str) //проверяем что после редиректа идет команда а не
// пайпы или редиректы
{
	int	i;

	i = 0;
	ft_redirect_find(str, &i);
	while (str[i])
	{
		if (str[i])
			i++;
		if (str[i] == str[i - 1])
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 0 || str[i] == '|' || str[i] == '<' || str[i] == '>')
			return (1);
		ft_redirect_find(str, &i);
	}
	return (0);
}

int	ft_prepars_command(char *str, int *i)
{
	while (str[*i] && str[*i] != '|')
	{
		if (str[*i] == '>' || str[*i] == '<')
		{
			(*i)++;
			if (str[*i] == str[*i - 1])
				(*i)++;
			while (str[*i] == ' ')
				(*i)++;
			if (!str[*i] || str[*i] == '>' || str[*i] == '<' || str[*i] == '|')
				return (1);
		}
		else if (str[*i] == '\'')
			ft_bkslash1(str, i);
		else if (str[*i] == '\"')
			ft_bkslash2(str, i);
		else
			(*i)++;
	}
	return (0);
}

int	ft_preparser(char *str)
{
	int		i;

	if (ft_prepars_1(str) != 0 || ft_prepars_2(str) != 0)
		return (1);
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 0 || str[i] == '|')
			return (1);
		if (ft_prepars_command(str, &i) != 0)//проверяем что есть команда
			return (1);
		if (str[i] == '|')
		{
			i++;
			if (str[i] == 0)
				return (1);
		}
		else
			break ;
	}
	return (0);
}
