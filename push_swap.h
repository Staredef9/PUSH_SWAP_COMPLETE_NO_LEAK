/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:02:10 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/31 15:30:32 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "Libft/libft.h"
# define FT_INTMAX 2147483647
# define FT_INTMIN -2147483647

typedef struct t_list{
	int				value;
	struct t_list	*next;
}	t_list;

void		free_split(char **real_argv);
void		list_free(t_list **head);
void		list_add_end(t_list **head, int value);
void		list_populate(t_list **head, char **argv, int argc);
void		list_print(t_list **head);
int			list_size(t_list *head);
void		sa(t_list **head);
void		sb(t_list **head_2);
void		ss(t_list **head, t_list **head_2);
int			push(t_list **head, t_list **head_2);
int			pa(t_list **head, t_list **head_2);
int			pb(t_list **head_2, t_list **head);
void		ra(t_list **head);
void		rb(t_list **head_2);
void		rr(t_list **head, t_list **head_2);
void		rra(t_list **head);
void		rrb(t_list **head_2);
void		rrr(t_list **head, t_list **head_2);
void		rotate(t_list **head);
void		reverse_rotate(t_list **head);
void		check_arg(int stack, t_list **head, t_list **head_2);
void		three_arg(t_list **head);
void		four_arg(t_list **head, t_list **head_2);
void		five_arg(t_list **head, t_list **head_2);
void		sort_big_stack(t_list **head);
char		**ft_input_master(int *argc, char **argv);
int			execute(t_list *head, char **argv, t_list *head_2, int *arg);
int			find_less_min(t_list **head, int min);
int			find_min(t_list **head);
int			get_min(t_list **head, int check);
int			stack_is_sorted(t_list **head);
int			get_maximum_bits(t_list **head);
void		radix_sort(t_list **head, t_list **head_2, int digits_counter);
int			int_check(char *arg);
long int	ft_atoi_long(char *nptr);
int			check_doubles(int temp, t_list *head);
int			ft_swap(int *arr_1, int *arr_2);
void		ft_bubble_sort(int *arr, int size);
void		ft_mustachesort(t_list *head, int size);
int			ft_argv_size(char **real_argv);
#endif
