/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:12:27 by fsalvett          #+#    #+#             */
/*   Updated: 2023/04/03 10:00:25 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_arg(t_list **head, t_list **head_2)
{
	int	small[2];
	int	pushed;

	small[0] = find_min(head);
	small[1] = find_less_min(head, small[0]);
	pushed = 0;
	while (pushed != 2)
	{
		if ((*head)->value == small[0] || (*head)->value == small[1])
		{
			pb(head_2, head);
			pushed++;
		}
		else
			ra(head);
	}
	three_arg(head);
	if ((*head_2)->value < (*head_2)->next->value)
		sb(head_2);
	pa(head, head_2);
	pa(head, head_2);
}

int	digits_count(int number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		count++;
		number = number / 10;
	}
	return (count);
}

int	digits_most(t_list **head)
{
	int		max;
	t_list	*temp;

	temp = *head;
	max = 0;
	while (temp->next != NULL)
	{
		if (digits_count(temp->value) > max)
			max = digits_count(temp->value);
		temp = temp->next;
	}
	return (max);
}

void	check_arg(int stack, t_list **head, t_list **head_2)
{
	int	digits_counter;

	if (stack == 2)
	{
		if ((*head)->value > (*head)->next->value)
			sa(head);
	}
	else if (stack == 3)
	{
		three_arg(head);
	}
	else if (stack == 4)
	{
		four_arg(head, head_2);
	}
	else if (stack == 5)
	{
		five_arg(head, head_2);
	}
	else
	{
		digits_counter = 0; //perche non passi direttamente 0? non ha senso visto che non passi l'indirizzo della variabile
		radix_sort(head, head_2, digits_counter);
	}
}
