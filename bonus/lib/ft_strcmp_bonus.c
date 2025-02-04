/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:19:57 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:42:29 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (404);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
	}
	return (0);
}
