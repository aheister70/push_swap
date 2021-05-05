/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 16:47:13 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/02 12:04:50 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int				error;
	int				first;
	int				size;
	int				min;
	int				max;
	int				size_a;
	int				size_b;
	int				half_a;
	int				halfnbr_a;
	int				half_b;
	int				halfnbr_b;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	int				amount_parts;
	int				sorted_parts;
	int				sorted_nbrs;
	int				sorted_min;
	int				sorted_max;
	int				range_min;
	int				range_max;
	int				rotated;
	int				amount_ops;
	int				*sorted_list;
}					t_data;

void	calculate_parts(t_data *data);
void	calculate_range(t_data *data, int chunk, int *sorted);
int		check_earlier(t_list **lst, int number);
int		check_in_range(t_list **lst, t_data *data);
int		check_integer(char *s);
int		check_s(char *str);
int		check_sorted(t_list **lst);
int		count_nbrs_range(t_list **lst, t_data *data);
int		*create_sorted(t_list **lst, t_data *data);
void	double_rotate(t_list **lst_a, t_list **lst_b, t_data *data, int d);
void	double_rrotate(t_list **lst_a, t_list **lst_b, t_data *data, int d);
void	double_swap(t_list **lst_a, t_list **lst_b, t_data *data, int d);
int		execute_ops(t_list **lst_a, t_list **lst_b, t_data *data, char *line);
int		find_first(t_list **lst, t_data *data);
int		get_ops(t_list **lst_a, t_list **lst_b, t_data *data);
void	init_data(t_list **lst_a, t_list **lst_b, t_data *data);
void	init_data_lst_a(t_list **lst_a, t_data *data);
void	init_data_lst_b(t_list **lst_b, t_data *data);
int		init_list(int argc, char **argv, t_list **lst_a);
int		part_sorted(t_list **lst, t_data *data);
void	push_a(t_list **lst_a, t_list **lst_b, t_data *data, int d);
void	push_b(t_list **lst_a, t_list **lst_b, t_data *data, int d);
void	sort_a(t_list **lst_a, t_list **lst_b, t_data *data);
void	sort_b(t_list **lst_a, t_list **lst_b, t_data *data, int c);
void	sorting(t_list **lst_a, t_list **lst_b, t_data *data);
void	sort_list_small(t_list **lst_a, t_data *data, int c);
void	sort_list_medium(t_list **lst_a, t_list **lst_b, t_data *data);
void	sort_list_big(t_list **lst_a, t_list **lst_b, t_data *data);
void	sort_part_lower(t_list **lst_a, t_list **lst_b, t_data *data);
void	sort_part_upper(t_list **lst_a, t_list **lst_b, t_data *data);
void	sort_push_medium(t_list **lst_a, t_list **lst_b, t_data *data, int c);
void	swap(t_list **lst, t_data *data, int c, int d);
void	swap_push_a(t_list **lst_a, t_list **lst_b, t_data *data);
void	rotate(t_list **lst, t_data *data, int c, int d);
void	rotate_push_a(t_list **lst_a, t_list **lst_b, t_data *data);
void	rrotate(t_list **lst, t_data *data, int c, int d);
void	write_result(t_list **lst_a, t_data *data);

char	*ft_realloc(char *left, int new_len);
char	*ft_fillstr(char *s, int start, int c);
char	*fill_buf(int fd);
char	*fill_left(char *left, char *buf);
char	*ft_filljoin(char *s1, char *s2, char *join_s, int len);
int		get_next_line(int fd, char **line);
int		get_line(int fd, char **line);
int		ft_nl(char *s);
char	*ft_strjoin(char *left, char *buf);
size_t	ft_strlen(const char *s);

void	print_list(t_list *lst_a);

#endif