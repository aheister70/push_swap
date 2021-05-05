/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/11 11:27:51 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/27 13:35:41 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** PART_SORTED - check if last part (of 5 numbers) is already ordered
** SORT_PUSH_MEDIUM = pushes integers to the other stack while 
**		positioning them to the right spot
** SORT_LIST_MEDIUM = sorts 4-5 integers in max 10 operations
*/

#include "../../includes/push_swap.h"

int	part_sorted(t_list **lst, t_data *data)
{
	int		i;
	int		hold;
	t_list	*tmp_lst;

	i = 1;
	tmp_lst = *lst;
	hold = tmp_lst->nbr;
	while (tmp_lst->next)
	{
		tmp_lst = tmp_lst->next;
		if (tmp_lst->nbr > (tmp_lst->prev)->nbr)
			hold = tmp_lst->nbr;
		if (tmp_lst->nbr == data->min_a)
		{
			while (tmp_lst->next && (tmp_lst->nbr < (tmp_lst->next)->nbr)
				&& (tmp_lst->next)->nbr < hold)
			{
				i++;
				tmp_lst = tmp_lst->next;
			}
			return (i);
		}
	}
	return (0);
}

void	sort_push_medium(t_list **lst_a, t_list **lst_b, t_data *data, int c)
{
	if (c == 0)
	{
		while ((*lst_a)->nbr == data->min_a && data->size_a > 3)
			push_b(lst_a, lst_b, data, 0);
		if (ft_lstlast(*lst_a)->nbr == data->min_a
			|| (ft_lstlast(*lst_a)->prev)->nbr == data->min_a)
			rrotate(lst_a, data, 'a', 0);
		else
			rotate(lst_a, data, 'a', 0);
	}
	if (c == 1)
	{
		push_a(lst_a, lst_b, data, 0);
		if ((*lst_a)->nbr < data->halfnbr_a)
			swap_push_a(lst_a, lst_b, data);
		else if ((*lst_a)->nbr > data->halfnbr_a)
			rotate_push_a(lst_a, lst_b, data);
	}		
}

void	sort_list_medium(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int	nbr_sorted;
	int	sorted;

	nbr_sorted = part_sorted(lst_a, data);
	if (nbr_sorted == 4 || nbr_sorted == 3)
	{
		if ((*lst_a)->nbr == data->max_a && nbr_sorted == 3)
			swap(lst_a, data, 'a', 0);
		rotate(lst_a, data, 'a', 0);
	}
	sorted = check_sorted(lst_a);
	while (data->size_a > 3 && sorted == 0)
	{
		sort_push_medium(lst_a, lst_b, data, 0);
		sorted = check_sorted(lst_a);
	}
	sort_list_small(lst_a, data, 'a');
	sorted = check_sorted(lst_a);
	while (data->size_b > 0 || sorted == 0)
	{
		sort_push_medium(lst_a, lst_b, data, 1);
		sorted = check_sorted(lst_a);
	}
}
