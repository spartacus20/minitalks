/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:19:09 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/15 11:39:12 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	i;
	int	count;

	i = 0;
	count = ft_lstsize(lst);
	if (!lst || !f)
		return ;
	while (i < count)
	{
		f(lst->content);
		lst = lst->next;
		i++;
	}
}
