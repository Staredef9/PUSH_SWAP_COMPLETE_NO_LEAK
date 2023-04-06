/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:57:57 by fsalvett          #+#    #+#             */
/*   Updated: 2023/04/03 10:08:43 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mustachesort(t_list *head, int size)
{
	int		*arr;
	int		i;
	t_list	*temp;
	t_list	*temp_2;

	temp = head;
	i = -1;
	arr = ft_calloc(size + 1, sizeof(int));
	//arr = malloc(sizeof(int) * size);
	while (++i < size)
	{
		arr[i] = temp->value;
		temp = temp->next;
	}
	ft_bubble_sort(arr, size);
	temp_2 = head;
	while (temp_2 != NULL)
	{
		i = 0;
		while (arr[i] != temp_2->value)
			i++;
		temp_2->value = i;
		temp_2 = temp_2->next;
	}
	free (arr);
}

void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	y = 0;
	while (i < size)
	{
		y = 0;
		while (y < size - i)
		{
			if (arr[y] > arr[y + 1])
			{
				temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}
			y++;
		}
		i++;
	}
}

int	get_maximum_bits(t_list **head)
{
	t_list	*temp;
	int		max;
	int		maximum_bits;

	temp = *head;
	max = temp->value;
	maximum_bits = 0;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	while ((max >> maximum_bits) != 0)
		maximum_bits++;
	return (maximum_bits);
}

void	radix_sort(t_list **head, t_list **head_2, int digits_counter)
{
	t_list	*temp;
	int		size_counter;
	int		size;
	int		maximum_bits;

	temp = *head;
	size = list_size(temp);
	ft_mustachesort(temp, size);
	maximum_bits = get_maximum_bits(head);
	while (digits_counter <= maximum_bits && stack_is_sorted(head) == -1)
	{
		size_counter = 0;
		while (size_counter++ < size)
		{
			temp = *head;
			if (((temp->value >> digits_counter) & 1) == 1)
				ra(head);
			else
				pb(head_2, head);
		}
		while (list_size(*head_2) != 0)
			pa(head, head_2);
		digits_counter++;
	}
}
