/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@42abudhabi.ae>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:58:24 by kamin             #+#    #+#             */
/*   Updated: 2022/03/17 17:02:09 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "do_op.c"
// #include "error_handling.c"
// #include "list_management.c"
// #include "push_stack.c"
// #include "push_swap.c"
// #include "quicksort.c"
// #include "rotate_stack.c"
// #include "swap_stack.c"
// #include "utils.c"
// #include "../libft/libft.h"
// #include "../libft/ft_checkdup.c"
// #include "../libft/ft_split_wc.c"
// #include "../libft/ft_isnum.c"
// #include "../libft/ft_atoi.c"
// #include "../libft/ft_isdigit.c"
// #include "../libft/ft_isint.c"
// #include "../libft/ft_strcmp.c"
// #include "../libft/ft_strlcpy.c"
// #include "../libft/ft_strlen.c"
// #include "checks.c"



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
