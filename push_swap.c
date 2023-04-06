/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:14:24 by fsalvett          #+#    #+#             */
/*   Updated: 2023/04/03 11:03:31 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arguments_legit(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && ft_isdigit(argv[i][1]) == 1)
		{
			if (int_check(argv[i]) == 0)
				return (0);
			i++;
		}
		else if (ft_isdigit((argv[i][0])) != 1)
		{
			return (0);
		}
		else if (int_check(argv[i]) == 0)
			return (0);
		else
			i++;
	}
	return (1);
}

long int	ft_atoi_long(char *nptr)
{
	long int	integer;
	long int	i;
	long int	sign;

	sign = 1;
	i = 0;
	integer = 0;
	while (nptr[i] == 32 || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-' && (ft_isdigit(nptr[i + 1]) == 1))
	{	
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+' && (ft_isdigit(nptr[i + 1]) == 1))
	{
		sign = 1;
		i++;
	}
	while ((ft_isdigit(nptr[i]) == 1))
	{
		integer = (integer * 10) + (nptr[i] - '0');
		i++;
	}
	return (integer * sign);
}

int	check_doubles(int temp, t_list *head)
{
	while (head != NULL)
	{
		if (temp == head->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	execute(t_list *head, char **argv, t_list *head_2, int *arg)
{
	list_populate(&head, argv, arg[0]);
	if (stack_is_sorted(&head) == 1)
	{
		list_free(&head);
		return (0);
	}
	//head_2 = (t_list *)malloc(sizeof(t_list)); che cazzo allochi per mettere a NULL subito dopo?
	head_2 = NULL; //cioe QUI!
	check_arg(arg[1], &head, &head_2);
	if (head_2)
		list_free(&head_2);
	list_free(&head);
	return (0);
}

int	main(int argc, char **argv)
{	
	t_list	*head;
	t_list	*head_2;
	int		arg[2];
	char	**real_argv;

	if (argc == 1)
		return (write(1, "Input invalido\n", 15)); //cosi non entra e non spacca tutto :D
	head = NULL;
	head_2 = NULL;
	real_argv = ft_input_master(&argc, argv);
	if (real_argv[2] != NULL) //accrocchio nel caso ci sia solo un numero
	{
		if (arguments_legit(argc, real_argv) == 0)
			write(1, "Error\n", 6);
		else
		{
			arg[0] = argc;
			arg[1] = argc - 1;
			execute(head, real_argv, head_2, arg);
		}
	}
	free_split(real_argv); //ora lo fa sempre visto che alloca sempre
}
