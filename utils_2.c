/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:11:19 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/31 11:14:05 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **head_2)
{
	rotate(head_2);
	write(1, "rb\n", 3);
}

void	rr(t_list **head, t_list **head_2)
{
	rotate(head);
	rotate(head_2);
	write(1, "rr\n", 3);
}

void	rra(t_list **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_list **head_2)
{
	reverse_rotate(head_2);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **head, t_list **head_2)
{
	reverse_rotate(head);
	reverse_rotate(head_2);
	write(1, "rrr\n", 4);
}
