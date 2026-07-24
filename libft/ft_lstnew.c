/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:29:25 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:48:20 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_linked;

	new_linked = malloc(sizeof(t_list));
	if (!new_linked)
	{
		return (NULL);
	}
	new_linked->content = content;
	new_linked->next = NULL;
	return (new_linked);
}
