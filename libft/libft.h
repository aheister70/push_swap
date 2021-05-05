/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 14:52:57 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/24 13:20:59 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int					ft_atoi(const char *str);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdel(t_list **lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int nbr);
int					ft_lstsize(t_list **lst);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
