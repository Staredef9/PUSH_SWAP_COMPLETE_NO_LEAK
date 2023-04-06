/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:10:53 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/31 12:11:56 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **head, t_list **head_2)
{
	t_list	*tmp;
	t_list	*stack_to;
	t_list	*stack_from;

	if (list_size(*head_2) == 0)
		return (-1);
	stack_to = *head;
	stack_from = *head_2;
	tmp = stack_from;
	stack_from = stack_from->next;
	*head_2 = stack_from;
	tmp->next = stack_to;
	*head = tmp;
	return (0);
}

int	pa(t_list **head, t_list **head_2)
{
	if (push(head, head_2) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **head_2, t_list **head)
{
	if (push(head_2, head) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}

void	ss(t_list **head, t_list **head_2)
{
	sa(head);
	sb(head_2);
	write(1, "ss\n", 3);
}
