/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 15:27:27 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/02 12:39:13 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
** SORT_A - finds and transports the next int to stack a (highest or 
**				lowest in stack depending on upper or lower part)
** SORT_B - transports an int from stack b to the upper or lower part of stack b
** SORT_PART_UPPER - sorts a chunk with lower ints than the middle chunk
** SORT_PART_BOTTOM - sorts a chunk with higher ints than the middle chunk
** SORT_LIST_BIG = sorts > 5 integers in chunks (amount depends
**					on amount of integers)
*/

#include "../../includes/push_swap.h"

void	sort_a(t_list **lst_a, t_list **lst_b, t_data *data)
{
	if (data->size_b > 1 && find_first(lst_b, data) == 1)
	{
		while ((*lst_b)->nbr != data->max_b)
			rotate(lst_b, data, 'b', 0);
	}
	if (data->size_b > 1 && find_first(lst_b, data) == 2)
	{
		while ((*lst_b)->nbr != data->max_b)
			rrotate(lst_b, data, 'b', 0);
	}
	push_a(lst_a, lst_b, data, 0);
}

void	sort_b(t_list **lst_a, t_list **lst_b, t_data *data, int c)
{
	push_b(lst_a, lst_b, data, 0);
	if (data->size_b == 3)
	{
		sort_list_small(lst_b, data, 'b');
		init_data(lst_a, lst_b, data);
	}
	if (data->size_b > 3 && (*lst_b)->nbr > ((*lst_b)->next)->nbr)
		swap(lst_b, data, 'b', 0);
	else if (c == 0 && data->size_b > 3 && (*lst_b)->nbr < data->halfnbr_b)
	{
		if (data->size_b > 3 && (*lst_b)->nbr < data->halfnbr_b)
		{
			if (check_in_range(lst_a, data) == 0
				&& (*lst_a)->nbr != data->sorted_min)
				double_rotate(lst_a, lst_b, data, 0);
			else
				rotate(lst_b, data, 'b', 0);
		}
	}	
	else if (c == 1 && data->size_b > 3 && (*lst_b)->nbr < data->halfnbr_b)
		rrotate(lst_b, data, 'b', 0);
}

void	sort_part_upper(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int	i;
	int	nbrs_in_range;

	i = 0;
	nbrs_in_range = count_nbrs_range(lst_a, data);
	while ((data->sorted_nbrs == 0 && i < nbrs_in_range)
		|| (data->sorted_nbrs > 0 && (*lst_a)->nbr != data->sorted_min))
	{
		if (check_in_range(lst_a, data) == 1)
		{
			sort_b(lst_a, lst_b, data, 0);
			i++;
		}
		else if (check_in_range(lst_a, data) == 0
			&& (*lst_a)->nbr != data->sorted_min)
			rotate(lst_a, data, 'a', 0);
	}
	init_data(lst_a, lst_b, data);
	data->sorted_min = data->min_b;
	if (data->sorted_nbrs == 0)
		data->sorted_max = data->max_b;
	data->sorted_nbrs = data->sorted_nbrs + data->size_b;
	while (data->size_b > 0)
		sort_a(lst_a, lst_b, data);
}

void	sort_part_lower(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int	i;
	int	nbrs_in_range;
	int	rotations;

	nbrs_in_range = count_nbrs_range(lst_a, data);
	rotations = data->size - data->sorted_nbrs;
	while (rotations > 0)
	{
		if (check_in_range(lst_a, data) == 0)
			rrotate(lst_a, data, 'a', 0);
		if (check_in_range(lst_a, data) == 1)
			sort_b(lst_a, lst_b, data, 1);
		rotations--;
	}
	init_data(lst_a, lst_b, data);
	data->sorted_nbrs = data->sorted_nbrs + data->size_b;
	data->sorted_max = data->max_b;
	while (data->size_b > 0)
		sort_a(lst_a, lst_b, data);
	i = 0;
	while (i < nbrs_in_range)
	{
		rotate (lst_a, data, 'a', 0);
		i++;
	}
}

void	sort_list_big(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int		upper;
	int		lower;
	int		*sorted;

	calculate_parts(data);
	sorted = create_sorted(lst_a, data);
	upper = (data->amount_parts / 2) + 1;
	lower = upper + 1;
	while (data->sorted_parts < data->amount_parts)
	{
		init_data(lst_a, lst_b, data);
		if ((data->sorted_parts % 2) == 0)
		{
			calculate_range(data, upper, sorted);
			sort_part_upper(lst_a, lst_b, data);
			upper--;
		}
		else if ((data->sorted_parts % 2) == 1)
		{
			calculate_range(data, lower, sorted);
			sort_part_lower(lst_a, lst_b, data);
			lower++;
		}
		data->sorted_parts = data->sorted_parts + 1;
	}
}
