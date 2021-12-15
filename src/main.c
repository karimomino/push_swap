/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:58:24 by kamin             #+#    #+#             */
/*   Updated: 2021/12/15 02:21:49 by kamin            ###   ########.fr       */
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
	int	errors;
	
	errors = check_input(argc, argv);
	if (argc > 1 && errors > 0)
		printf("The Input Is Valid\n");
	else
		print_errors(errors);
	return (0);
}
