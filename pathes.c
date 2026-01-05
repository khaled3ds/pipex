/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:25:01 by kadas             #+#    #+#             */
/*   Updated: 2025/11/17 19:07:02 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **words)
{
	int	i;

	i = 0;
	if (!words)
		return ;
	while (words[i])
		free(words[i++]);
	free(words);
}

static char	*joiner(char *split, char *cmd)
{
	char	*temp;
	char	*newstr;

	if (!split || !cmd)
		return (NULL);
	temp = ft_strjoin(split, "/");
	if (!temp)
		return (NULL);
	newstr = ft_strjoin(temp, cmd);
	if (!newstr)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (newstr);
}

static char	*path(char **env)
{
	int		i;
	int		j;
	int		length;
	char	*pathes;

	i = 0;
	while (env[i])
	{
		j = 0;
		if (!(ft_strncmp(env[i], "PATH=", 5)))
		{
			length = (ft_strlen(env[i])) - 5;
			while (env[i][j] != '=' && env[i][j])
				j++;
			if (env[i][j] == '=')
				j++;
			pathes = ft_substr(env[i], j, length);
			return (pathes);
		}
		i++;
	}
	return (NULL);
}

static char	*check(char **split, char *joined, char *cmd)
{
	int	i;

	i = 0;
	while (split[i])
	{
		joined = joiner(split[i], cmd);
		if (!joined)
		{
			free_all(split);
			return (NULL);
		}
		if ((access(joined, X_OK)) == 0)
		{
			free_all(split);
			return (joined);
		}
		free(joined);
		i++;
	}
	free_all(split);
	return (NULL);
}

char	*neededpath(char **env, char *cmd)
{
	char	*p;
	char	**split;
	int		i;
	char	*joined;
	char	*ret;

	i = 0;
	joined = NULL;
	p = path(env);
	if (!p)
		return (NULL);
	split = ft_split(p, ':');
	free(p);
	if (cmd[0] == '/' && (access(cmd, X_OK)) == 0)
	{
		free_all(split);
		return (cmd);
	}
	ret = check(split, joined, cmd);
	if (!ret)
	{
		return (NULL);
	}
	return (ret);
}
