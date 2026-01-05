/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:12:14 by kadas             #+#    #+#             */
/*   Updated: 2025/08/12 20:51:27 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	d = malloc((l + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
