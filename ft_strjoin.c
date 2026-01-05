/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:10:06 by kadas             #+#    #+#             */
/*   Updated: 2025/11/17 19:00:21 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*c;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	c = malloc(s1len + s2len + 1);
	if (!c)
		return (NULL);
	while (++i < s1len)
		c[i] = s1[i];
	i = -1;
	while (++i < s2len)
		c[i + s1len] = s2[i];
	c[s1len + s2len] = '\0';
	return (c);
}
