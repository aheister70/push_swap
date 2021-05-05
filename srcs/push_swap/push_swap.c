/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 11:01:12 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/02 13:23:00 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sorting(t_list **lst_a, t_list **lst_b, t_data *data)
{
	if (data->size_a == 1 || check_sorted(lst_a) == 1)
		return ;
	else
	{
		if (data->size_a < 3)
			swap(lst_a, data, 'a', 0);
		else if (data->size_a < 4)
			sort_list_small(lst_a, data, 'a');
		else if (data->size_a >= 4 && data->size_a < 6)
			sort_list_medium(lst_a, lst_b, data);
		else
			sort_list_big(lst_a, lst_b, data);
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_data	data;
	int		ok;

	lst_a = NULL;
	lst_b = NULL;
	ok = init_list(argc, argv, &lst_a);
	if (lst_a != NULL && ok == 1)
	{
		data.first = 0;
		init_data(&lst_a, &lst_b, &data);
		sorting(&lst_a, &lst_b, &data);
	}
	else
		write(1, "Error\n", 6);
	while (lst_a)
		ft_lstdel(&lst_a);
	while (lst_b)
		ft_lstdel(&lst_b);
	return (0);
}
