/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/11 11:26:31 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/27 13:35:47 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
** SORT_LIST_SMALL - sorts 3 integers in max 2 operations
*/

#include "../../includes/push_swap.h"

void	sort_list_small(t_list **lst, t_data *data, int c)
{
	int	last;

	last = ft_lstlast(*lst)->nbr;
	if (c == 'a')
	{
		if ((*lst)->nbr != data->max_a && last != data->max_a)
			rrotate(lst, data, c, 0);
		else if ((*lst)->nbr == data->max_a)
			rotate(lst, data, c, 0);
		if ((*lst)->nbr > ((*lst)->next)->nbr)
			swap(lst, data, c, 0);
	}
	else if (c == 'b')
	{
		if ((*lst)->nbr != data->min_b && last != data->min_b)
			rrotate(lst, data, c, 0);
		else if ((*lst)->nbr == data->min_b)
			rotate(lst, data, c, 0);
		if ((*lst)->nbr < ((*lst)->next)->nbr)
			swap(lst, data, c, 0);
	}
}
