/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 17:01:06 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/24 11:13:23 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->prev = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = new;
	(*lst)->prev = new;
}
