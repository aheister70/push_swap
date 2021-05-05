/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_multi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 15:13:05 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/02 12:18:42 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** DOUBLE_SWAP - swaps both stack a en b at the same time
** DOUBLE_ROTATE - rotates both stack a en b at the same time
** DOUBLE_RROTATE - reverse rotate both stack a en b at the same time
** SWAP_PUSH_A - swaps and pushes an integer from and to stack a until
**				it is in the right position
** ROTATE_PUSH_A - rotates and pushes an integer from and to stack a until
**				it is in the right position
*/

#include "../includes/push_swap.h"

void	double_swap(t_list **lst_a, t_list **lst_b, t_data *data, int d)
{
	if (!lst_a || !lst_b)
		return ;
	swap(lst_a, data, 'a', 1);
	swap(lst_b, data, 'b', 1);
	if (d == 0)
		write(1, "ss\n", 3);
	data->amount_ops++;
}

void	double_rotate(t_list **lst_a, t_list **lst_b, t_data *data, int d)
{
	rotate(lst_a, data, 'a', 1);
	rotate(lst_b, data, 'b', 1);
	if (d == 0)
		write(1, "rr\n", 3);
	data->amount_ops++;
}

void	double_rrotate(t_list **lst_a, t_list **lst_b, t_data *data, int d)
{
	rrotate(lst_a, data, 'a', 1);
	rrotate(lst_b, data, 'b', 1);
	if (d == 0)
		write(1, "rrr\n", 4);
	data->amount_ops++;
}

void	swap_push_a(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int	i;

	i = 0;
	while ((*lst_a)->nbr > ((*lst_a)->next)->nbr)
	{
		swap(lst_a, data, 'a', 0);
		if (data->size_a > 2 && ((*lst_a)->next)->nbr
			> (((*lst_a)->next)->next)->nbr)
		{
			push_b(lst_a, lst_b, data, 0);
			i++;
		}
	}
	while (i > 0)
	{
		push_a(lst_a, lst_b, data, 0);
		i--;
	}
	init_data(lst_a, lst_b, data);
}

void	rotate_push_a(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int	i;

	i = 0;
	while ((*lst_a)->nbr > (*lst_a)->next->nbr
		&& (*lst_a)->nbr < ft_lstlast(*lst_a)->nbr)
	{
		rrotate(lst_a, data, 'a', 0);
		push_b(lst_a, lst_b, data, 0);
		i++;
	}
	rotate (lst_a, data, 'a', 0);
	while (i > 0)
	{
		push_a(lst_a, lst_b, data, 0);
		rotate (lst_a, data, 'a', 0);
		i--;
	}
	init_data(lst_a, lst_b, data);
}
