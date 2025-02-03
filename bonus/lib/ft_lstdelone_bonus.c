/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:04:04 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/22 09:58:37 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

// void	del(void *content)
// {
// 	free(content);
// }
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
