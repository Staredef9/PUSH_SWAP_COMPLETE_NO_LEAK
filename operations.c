/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:50:01 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/31 11:56:56 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

void	three_arg(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *head;
	second = (*head)->next;
	third = (*head)->next->next;
	if (second->value > first->value && third->value > second->value)
		return ;
	else if (third->value > first->value && third->value < second->value)
	{
		rra(head);
		sa(head);
	}
	else if (first->value > second->value && first->value < third->value)
		sa(head);
	else if (first->value < second->value && first->value > third->value)
		rra(head);
	else if (second->value < first->value && second->value > third->value)
	{
		ra(head);
		sa(head);
	}
	else if (third->value < first->value && third->value > second->value)
		ra(head);
}

void	four_arg(t_list **head, t_list **head_2)
{
	int	min;
	int	pushed;

	min = find_min(head);
	pushed = 0;
	while (pushed != 1)
	{
		if ((*head)->value == min)
		{
			pb(head_2, head);
			pushed++;
		}
		else
			ra(head);
	}
	three_arg(head);
	pa(head, head_2);
}

int	find_min(t_list **head)
{
	t_list	*temp;
	int		min;

	min = (*head)->value;
	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	if (temp->value < min)
		min = temp->value;
	return (min);
}

int	find_less_min(t_list **head, int min)
{
	t_list	*temp;
	int		less_min;

	temp = *head;
	if (temp->value != min)
		less_min = temp->value;
	else if (temp->value == min)
		less_min = temp->next->value;
	while (temp->next != NULL)
	{
		if (temp->value < less_min && min != temp->value)
		{
			less_min = temp->value;
		}
		temp = temp->next;
	}
	if (temp->value < less_min && min != temp->value)
	{
		less_min = temp->value;
	}
	return (less_min);
}
