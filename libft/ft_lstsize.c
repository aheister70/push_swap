/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 13:42:44 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/24 13:21:19 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	int		len;
	t_list	*lst_tmp;

	len = 0;
	lst_tmp = *lst;
	while (lst_tmp)
	{
		lst_tmp = lst_tmp->next;
		len++;
	}
	return (len);
}
