/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 15:24:13 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/24 13:14:15 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CHECK_S - checks if stdin input has only numbers 0-9
** CHECK_INTEGER - checks if number is >= -2147483648 && <= 2147483647
** CHECK_EARLIER - checks stdin input - are there no duplicates
** CHECK_IN_RANGE - check if integer in stack A is within given range
** CHECK_SORTED - check if stack A is sorted
*/

#include "../includes/push_swap.h"

int	check_s(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	check_integer(char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	if (str[i] == '-')
		b = -1;
	if (b == 1 && ft_atoi(str) < 0)
		return (0);
	else if (b == -1 && ft_atoi(str) > 0)
		return (0);
	return (1);
}

int	check_earlier(t_list **lst, int nbr)
{
	t_list	*lst_tmp;

	lst_tmp = *lst;
	while (lst_tmp)
	{
		if (lst_tmp->nbr == nbr)
			return (0);
		lst_tmp = lst_tmp->next;
	}
	return (1);
}

int	check_in_range(t_list **lst, t_data *data)
{
	if ((*lst)->nbr > data->range_min && (*lst)->nbr <= data->range_max)
		return (1);
	return (0);
}

int	check_sorted(t_list **lst)
{
	t_list	*lst_tmp;

	lst_tmp = *lst;
	while (lst_tmp->next)
	{
		if (lst_tmp->nbr > (lst_tmp->next)->nbr)
			return (0);
		lst_tmp = lst_tmp->next;
	}
	return (1);
}
