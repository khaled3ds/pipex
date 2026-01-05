/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:40:34 by kadas             #+#    #+#             */
/*   Updated: 2025/10/09 18:56:08 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_al(char **words, size_t i)
{
	while (i > 0)
		free(words[--i]);
	free(words);
}

static int	countword(char const *s, char c)
{
	size_t	counter;
	size_t	in_word;
	size_t	i;

	i = 0;
	in_word = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			counter++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (counter);
}

static char	*mydup(const char *s, int start, int end)
{
	char	*d;
	size_t	i;

	d = malloc((end - start + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (start < end)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

static int	strings(char const *s, char c, size_t counter, char **words)
{
	size_t	j;
	size_t	k;
	size_t	i;

	j = 0;
	i = -1;
	while (s[j] == c)
		j++;
	k = j;
	while (++i < counter)
	{
		while (s[j] != c && s[j] != '\0')
			j++;
		words[i] = mydup(s, k, j);
		if (!words[i])
		{
			free_al(words, i);
			return (-1);
		}
		while (s[j] == c)
			j++;
		k = j;
	}
	words[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	counter;
	char	**words;

	if (!s)
		return (NULL);
	counter = countword(s, c);
	words = malloc(sizeof(char *) * (counter + 1));
	if (!words)
		return (NULL);
	if (strings(s, c, counter, words) == -1)
		return (NULL);
	return (words);
}

// int main()
// {
//     char s[] = "ccccayhamcckhaledccadbc";
//     printf("%ld", countword(s, 'c'));
// }
