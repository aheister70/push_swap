/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:41:47 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/02 13:23:05 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** EXECUTE_OPS - executes the operations that are printed in stdin
** GET_OPS - collects the operations that are printed in stdin
** WRITE_RESULT - writes OK/KO depending on the sorting outcome
** MAIN - starts checker
*/

#include "../../includes/push_swap.h"

int	execute_ops(t_list **lst_a, t_list **lst_b, t_data *data, char *line)
{
	if (ft_strncmp(line, "ss\0", 3) == 0)
		double_swap(lst_a, lst_b, data, 2);
	else if (ft_strncmp(line, "rr\0", 3) == 0)
		double_rotate(lst_a, lst_b, data, 2);
	else if (ft_strncmp(line, "rrr\0", 4) == 0)
		double_rrotate(lst_a, lst_b, data, 2);
	else if (ft_strncmp(line, "sa\0", 3) == 0)
		swap(lst_a, data, 'a', 2);
	else if (ft_strncmp(line, "ra\0", 3) == 0)
		rotate(lst_a, data, 'a', 2);
	else if (ft_strncmp(line, "rra\0", 4) == 0)
		rrotate(lst_a, data, 'a', 2);
	else if (ft_strncmp(line, "sb\0", 3) == 0)
		swap(lst_b, data, 'b', 2);
	else if (ft_strncmp(line, "rb\0", 3) == 0)
		rotate(lst_b, data, 'b', 2);
	else if (ft_strncmp(line, "rrb\0", 4) == 0)
		rrotate(lst_b, data, 'b', 2);
	else if (ft_strncmp(line, "pa\0", 3) == 0)
		push_a(lst_a, lst_b, data, 2);
	else if (ft_strncmp(line, "pb\0", 3) == 0)
		push_b(lst_a, lst_b, data, 2);
	else
		return (1);
	return (0);
}

int	get_ops(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int		res;
	char	*line;

	res = 1;
	data->first = 0;
	init_data(lst_a, lst_b, data);
	while (res > 0)
	{
		res = get_next_line(0, &line);
		if (res == 1)
		{
			if (execute_ops(lst_a, lst_b, data, line) == 1 )
			{
				data->error = 1;
				free (line);
				return (-1);
			}
			free(line);
		}
	}
	return (res);
}

void	write_result(t_list **lst_a, t_data *data)
{
	if (data->size_b == 0 && check_sorted(lst_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_data	data;
	int		res;

	if (argc < 2)
		return (0);
	lst_a = NULL;
	lst_b = NULL;
	res = init_list(argc, argv, &lst_a);
	if (lst_a != NULL && res == 1)
		res = get_ops(&lst_a, &lst_b, &data);
	if (res == 0 && data.error == 0)
		write_result(&lst_a, &data);
	else
		write(1, "Error\n", 6);
	while (lst_a)
		ft_lstdel(&lst_a);
	while (lst_b)
		ft_lstdel(&lst_b);
	return (0);
}
