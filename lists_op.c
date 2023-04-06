/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:08:35 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/31 12:10:36 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_free(t_list **head)
{
	t_list	*temp;

	if ((*head)->next == NULL)
	{
		free(head);
	}
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int	list_size(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	list_add_end(t_list **head, int value)
{
	t_list	*new;
	t_list	*temp;

	new = malloc(sizeof(t_list));
	new->value = value;
	new->next = NULL;
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void	list_populate(t_list **head, char **argv, int argc)
{
	int	i;
	int	temp;

	temp = 0;
	i = 1;
	if (i == 1)
	{
		*head = malloc(sizeof(t_list));
		(*head)->value = atoi(argv[i]);
		(*head)->next = NULL;
		i++;
	}
	while (i < argc)
	{
		temp = atoi(argv[i]);
		if (check_doubles(temp, *head) == 0)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		list_add_end(head, temp);
		i++;
	}
}

void	list_print(t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}
