/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:29:14 by kamin             #+#    #+#             */
/*   Updated: 2021/12/15 00:25:30 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This function will validate the input of the user to the program
** Params:
** 	NAME		TYPE		DESCRIPTION
** 	av			*String		The input from user to be validated.
** 	ac			Int			Number of params passed by the user to the program
*/
int	check_input(int ac, char **av)
{
	int	valid;

	valid = 1;
	if (ac == 2)
		valid = check_ione(av[1]);
	else if (ac > 2)
		valid = check_itwo(ac, av);
	return (valid);
}

int	check_ione(char *av)
{
	char	**tmp;
	int		i;
	int		ac2;
	int		valid;

	ac2 = ft_split_wc(av, ' ', &tmp);
	i = -1;
	valid = 1;
	if (ac2 == 0)
		return (-5);
	while (tmp[++i] && valid)
			valid = ft_isnum(tmp[i]);
	if (valid && ft_checkdup(ac2 + 1, tmp))
		valid = -3;
	return (valid);
}

int	check_itwo(int ac, char **av)
{
	int		i;
	int		valid;
	i = 0;
	valid = 1;
	while (av[++i] && valid)
			valid = ft_isnum(av[i]);
	if (valid && ft_checkdup(ac, av))
		valid = -3;
	return (valid);
}

void	print_errors(int error_code)
{
	printf("Error: %d", error_code);
}
