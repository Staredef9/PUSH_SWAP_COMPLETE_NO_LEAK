/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:45:54 by fsalvett          #+#    #+#             */
/*   Updated: 2023/04/03 11:02:14 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_check(char *arg)
{
	long int	val;

	val = ft_atoi_long(arg);
	if (val > FT_INTMAX || val < FT_INTMIN)
		return (0);
	else
		return (1);
}

void	ft_strcpy(char *dst, char *source)
{
	int	i;

	i = 0;
	while(source[i] != '\0')
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_argv_size(char **real_argv)
{
	int	i;

	i = 0;
	while(real_argv[i] != NULL)
		i++;
	return i;
}

void	free_split(char **real_argv)
{
	int	i; 

	i = 0;
	if (!real_argv)
		return ;
	while (real_argv[i] != NULL)
	{
		free(real_argv[i]);
		i++;
	}
	free(real_argv);
}

char **ft_dup_matrix(char **matrix) //cosi real_argv e' sempre allocata e liberi sempre.. memory leaks suck my libs
{
	int		i;
	int		size;
	char	**matrix_clone; 

	i = 0;
	size = ft_argv_size(matrix);
	matrix_clone = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		matrix_clone[i] = ft_strdup(matrix[i]);
		i++;
	}
	matrix_clone[i] = NULL;
	return (matrix_clone);
}

char	**ft_input_master(int *argc, char **argv)
{
	char	**real_argv;
	char	**fake_argv;
	int		i;
	int		j;

	if (*argc > 2)
		return (ft_dup_matrix(argv)); //se non duplichi poi non sai se e' mallocata o no, cosi liberi a prescindere e non hai problemi. altra opzione era friare solo se arc == 2
	// ho tolto l'if perche era sempre vero :D
	fake_argv = NULL;
	i = 0;
	fake_argv = ft_split(argv[1], ' ');
	i = ft_argv_size(fake_argv);
	real_argv = ft_calloc((i + 2), sizeof(char *)); //amore prima moltiplicazioni e poi addizzioni, te allocavi 8 * i + un byte :c
	//real_argv = malloc(sizeof(char *) * i + 1); //tuo
	real_argv[0] = ft_strdup(argv[0]);
	j = 1;
	while (j < i)
	{
		real_argv[j] = ft_strdup(fake_argv[j-1]);
		j++;
	}
	real_argv[j] = ft_strdup(fake_argv[j-1]);
	*argc = i + 1;
	free_split(fake_argv);
	return (real_argv);
}
