/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:33:04 by kadas             #+#    #+#             */
/*   Updated: 2025/11/17 19:00:45 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	slength;

	i = 0;
	if (!s)
		return (NULL);
	slength = ft_strlen(s);
	if (len == 0 || start >= slength)
		return (ft_strdup(""));
	if (len > (slength - start))
		len = slength - start;
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
