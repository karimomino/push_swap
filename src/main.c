/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:58:24 by kamin             #+#    #+#             */
/*   Updated: 2022/02/11 01:26:01 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//#include "../libft/libft.h"

/*
** This is the main function. It makes all the necessary
** calls to functions that will run the sorting algorithm.
*/
int	main(int argc, char *argv[])
{
	int		errors;
	int		elems;
	char	**numbers;

	errors = check_input(argc, argv);
	if (argc > 1 && errors > 0)
	{
		elems = ft_split_wc(argv[1], ' ', &numbers);
		push_swap(&numbers, elems);
	}
	else
		print_errors(errors);
	return (0);
}
