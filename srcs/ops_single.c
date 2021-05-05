/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_single.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 16:46:32 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 13:06:49 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** SWAP - 	swap the first 2 elements at the top of stack
** ROTATE - shift up all elements of stack by 1. The first element 
**			becomes the last one
** RROTATE - shift down all elements of stack by 1. The last element 
**			becomes the first one.
** PUSH_A - take the first element at the top of b and put it at the top of a. 
** PUSH_B - take the first element at the top of a and put it at the top of b.
*/

#include "../includes/push_swap.h"

void	swap(t_list **lst, t_data *data, int c, int d)
{
	t_list	*node1;
	t_list	*node2;
	int		tmp;

	if (*lst == NULL)
		return ;
	node1 = *lst;
	node2 = (*lst)->next;
	if (!node1 || !node2)
		return ;
	tmp = node1->nbr;
	node1->nbr = node2->nbr;
	node2->nbr = tmp;
	if (d == 0 || d == 2)
	{	
		data->amount_ops++;
		if (c == 'a' && d == 0)
			write(1, "sa\n", 3);
		else if (c == 'b' && d == 0)
			write(1, "sb\n", 3);
	}
}

void	rotate(t_list **lst, t_data *data, int c, int d)
{
	int		tmp;
	t_list	*lst_tmp;

	if (*lst == NULL)
		return ;
	lst_tmp = *lst;
	tmp = lst_tmp->nbr;
	while (lst_tmp != ft_lstlast(lst_tmp))
	{
		lst_tmp->nbr = (lst_tmp->next)->nbr;
		lst_tmp = lst_tmp->next;
	}
	lst_tmp->nbr = tmp;
	if (d == 0 || d == 2)
	{
		data->amount_ops++;
		if (c == 'a' && d == 0)
			write(1, "ra\n", 3);
		else if (c == 'b' && d == 0)
			write(1, "rb\n", 3);
	}
}

void	rrotate(t_list **lst, t_data *data, int c, int d)
{
	int		tmp;
	t_list	*node_l;

	if (*lst == NULL)
		return ;
	tmp = ft_lstlast(*lst)->nbr;
	node_l = ft_lstlast(*lst);
	while (node_l != *lst)
	{
		node_l->nbr = (node_l->prev)->nbr;
		node_l = node_l->prev;
	}
	node_l->nbr = tmp;
	if (d == 0 || d == 2)
	{
		data->amount_ops++;
		if (c == 'a' && d == 0)
			write(1, "rra\n", 4);
		else if (c == 'b' && d == 0)
			write(1, "rrb\n", 4);
	}
}

void	push_a(t_list **lst_a, t_list **lst_b, t_data *data, int d)
{
	int	tmp;

	if (*lst_b == NULL)
		return ;
	tmp = (*lst_b)->nbr;
	ft_lstdel(lst_b);
	if (*lst_a == NULL)
		*lst_a = ft_lstnew(tmp);
	else
		ft_lstadd_front(lst_a, ft_lstnew(tmp));
	data->size_a = data->size_a + 1;
	data->size_b = data->size_b - 1;
	data->amount_ops++;
	init_data(lst_a, lst_b, data);
	if (d == 0)
		write(1, "pa\n", 3);
}

void	push_b(t_list **lst_a, t_list **lst_b, t_data *data, int d)
{
	int	tmp;

	if (*lst_a == NULL)
		return ;
	tmp = (*lst_a)->nbr;
	ft_lstdel(lst_a);
	if (data->size_b == 0)
		*lst_b = ft_lstnew(tmp);
	else
		ft_lstadd_front(lst_b, ft_lstnew(tmp));
	data->size_a = data->size_a - 1;
	data->size_b = data->size_b + 1;
	data->amount_ops++;
	init_data(lst_a, lst_b, data);
	if (d == 0)
		write(1, "pb\n", 3);
}
