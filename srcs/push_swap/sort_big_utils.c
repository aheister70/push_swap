/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 11:40:29 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/02 08:32:21 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CALCULATE_PARTS - determines the amount of parts based on amount of ints
** COUNT_NBRS_RANGE - counts the number of integers in given range
** CALCULATE_RANGE - calculates the min en max of the current range
** CREATE_SORTED - creates a reference array with the ints sorted
** FIND_FIRST - checks the amount of rotations needed to get the
**              highest integer on top
*/

#include "../../includes/push_swap.h"

void	calculate_parts(t_data *data)
{
	if (data->size <= 20)
		data->amount_parts = 1;
	else if (data->size <= 100)
		data->amount_parts = 5;
	else if (data->size <= 200)
		data->amount_parts = 7;
	else if (data->size <= 350)
		data->amount_parts = 9;
	else if (data->size > 350)
		data->amount_parts = 11;
}

int	count_nbrs_range(t_list **lst, t_data *data)
{
	int		i;
	t_list	*lst_tmp;

	i = 0;
	lst_tmp = *lst;
	while (lst_tmp)
	{
		if (lst_tmp->nbr > data->range_min && lst_tmp->nbr <= data->range_max)
			i++;
		lst_tmp = lst_tmp->next;
	}
	return (i);
}

void	calculate_range(t_data *data, int chunk, int *sorted)
{
	int	part;

	part = data->size / data->amount_parts;
	if (chunk == 1)
		data->range_min = data->min - 1;
	else
		data->range_min = sorted[part * (chunk - 1)];
	if (chunk == data->amount_parts)
		data->range_max = data->max;
	else
		data->range_max = sorted[(part * chunk)];
	if (chunk == 1)
		free(sorted);
}

int	*create_sorted(t_list **lst, t_data *data)
{
	int		*sorted;
	t_list	*lst_tmp;
	int		nbr_next;
	int		i;

	i = 1;
	sorted = malloc((data->size + 1) * sizeof(int));
	sorted[0] = data->min;
	while (i < data->size)
	{
		nbr_next = data->max;
		lst_tmp = *lst;
		while (lst_tmp)
		{
			if (lst_tmp->nbr > sorted[i - 1] && lst_tmp->nbr < nbr_next)
				nbr_next = lst_tmp->nbr;
			lst_tmp = lst_tmp->next;
		}
		sorted[i] = nbr_next;
		i++;
	}
	sorted[i] = '\0';
	return (sorted);
}

int	find_first(t_list **lst, t_data *data)
{
	int		i;
	t_list	*lst_tmp;

	lst_tmp = *lst;
	i = 0;
	while (lst_tmp->next)
	{
		if (lst_tmp->nbr == data->max_b)
			break ;
		lst_tmp = lst_tmp->next;
		i++;
	}
	lst_tmp = ft_lstlast(lst_tmp);
	while (lst_tmp->prev)
	{
		if (lst_tmp->nbr == data->max_b)
			break ;
		lst_tmp = lst_tmp->prev;
		i--;
	}
	if (i < 0)
		return (1);
	else
		return (2);
}
