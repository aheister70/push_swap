/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/11 11:20:54 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/30 14:58:07 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_LIST - initializes the linked list from stdin input
** INIT_DATA_LST_A - initializes the data of stack a
** INIT_DATA_LST_B - initializes the data of stack b
** INIT_DATA - initializes global data and calls init_a en init_b
*/

#include "../includes/push_swap.h"

int	init_list(int argc, char **argv, t_list **lst_a)
{
	int			i;
	int			nbr;

	i = 1;
	while (i < argc)
	{
		if (check_s(argv[i]) == 0 || check_integer(argv[i]) == 0)
			return (0);
		else
		{
			nbr = ft_atoi(argv[i]);
			if (!*lst_a)
				*lst_a = ft_lstnew(nbr);
			else
			{
				if (check_earlier(lst_a, nbr) == 1)
					ft_lstadd_back(lst_a, ft_lstnew(nbr));
				else
					return (0);
			}	
		}
		i++;
	}
	return (1);
}

void	init_data_lst_a(t_list **lst_a, t_data *data)
{
	int		i;
	t_list	*lst_tmp;

	i = 1;
	lst_tmp = *lst_a;
	data->min_a = (*lst_a)->nbr;
	data->max_a = (*lst_a)->nbr;
	data->size_a = ft_lstsize(lst_a);
	data->half_a = (data->size_a / 2) + 1;
	while (lst_tmp)
	{
		if (lst_tmp->nbr < data->min_a)
			data->min_a = lst_tmp->nbr;
		else if (lst_tmp->nbr > data->max_a)
			data->max_a = lst_tmp->nbr;
		if (i == data->half_a)
			data->halfnbr_a = lst_tmp->nbr;
		lst_tmp = lst_tmp->next;
		i++;
	}
}

void	init_data_lst_b(t_list **lst_b, t_data *data)
{
	int		i;
	t_list	*lst_tmp;

	lst_tmp = *lst_b;
	i = 1;
	data->min_b = (*lst_b)->nbr;
	data->max_b = (*lst_b)->nbr;
	data->size_b = ft_lstsize(lst_b);
	data->half_b = (data->size_b / 2) + 1;
	while (lst_tmp)
	{
		if (lst_tmp->nbr < data->min_b)
			data->min_b = lst_tmp->nbr;
		else if (lst_tmp->nbr > data->max_b)
			data->max_b = lst_tmp->nbr;
		if (i == data->half_b)
			data->halfnbr_b = lst_tmp->nbr;
		lst_tmp = lst_tmp->next;
		i++;
	}
}

void	init_data(t_list **lst_a, t_list **lst_b, t_data *data)
{
	if (*lst_a)
		init_data_lst_a(lst_a, data);
	if (*lst_b)
		init_data_lst_b(lst_b, data);
	if (data->first == 0)
	{
		data->size = ft_lstsize(lst_a);
		data->sorted_parts = 0;
		data->sorted_nbrs = 0;
		data->size_b = 0;
		data->min = data->min_a;
		data->max = data->max_a;
		data->first = 1;
		data->error = 0;
	}
}
