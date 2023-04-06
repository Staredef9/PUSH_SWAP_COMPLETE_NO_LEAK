/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:04:33 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/31 12:07:05 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*new_head;
	t_list	*temp_end;

	temp = *head;
	new_head = (*head)->next;
	temp_end = *head;
	while (temp_end->next != NULL)
	{
		temp_end = temp_end->next;
	}
	temp_end->next = temp;
	temp->next = NULL;
	*head = new_head;
}

void	reverse_rotate(t_list **head)
{
	t_list	*temp_penultimate;
	t_list	*temp_end;

	temp_end = *head;
	temp_penultimate = *head;
	while (temp_end->next != NULL)
	{
		temp_end = temp_end->next;
	}
	while (temp_penultimate->next && temp_penultimate->next->next != NULL)
	{
		temp_penultimate = temp_penultimate->next;
	}
	temp_end->next = *head;
	temp_penultimate->next = NULL;
	*head = temp_end;
}

void	ra(t_list **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	sa(t_list **head)
{
	int	temp;

	if ((*head)->next != NULL)
	{
		temp = (*head)->value;
		(*head)->value = (*head)->next->value;
		(*head)->next->value = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **head_2)
{
	int	temp;

	if ((*head_2)->next != NULL)
	{
		temp = (*head_2)->value;
		(*head_2)->value = (*head_2)->next->value;
		(*head_2)->next->value = temp;
		write(1, "sb\n", 3);
	}
}
