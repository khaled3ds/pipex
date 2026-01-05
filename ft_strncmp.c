/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:10:19 by kadas             #+#    #+#             */
/*   Updated: 2025/10/08 20:23:31 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	tmp = 0;
	while ((s1[tmp] || s2[tmp]) && tmp < n)
	{
		if (s1[tmp] > s2[tmp])
			return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
		else if (s1[tmp] < s2[tmp])
			return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
		tmp++;
	}
	return (0);
}
