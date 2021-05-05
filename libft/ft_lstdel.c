/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 17:06:25 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/24 11:13:18 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst)
{
	t_list	*current;

	if (!*lst)
		return ;
	current = *lst;
	*lst = current->next;
	current->prev = ft_lstlast(*lst);
	free(current);
}
