/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:14 by kamin             #+#    #+#             */
/*   Updated: 2021/12/22 03:51:57 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "structs.h"

/*ERROR HANDLING FUNCTIONS*/
int		ft_isnum(char *s);
int		check_input(int ac, char **av);
int		check_ione(char *av);
int		check_itwo(int ac, char **av);
void	print_errors(int error_code);

/*QUICK SORT*/
int		partition(int **arr, int low, int high);
void	quicksort(int **arr, int low, int high);
void	swap(int *a, int *b);

/*UTILITIES*/
int		count_elems(char **stack);

#endif
