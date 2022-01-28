/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:14 by kamin             #+#    #+#             */
/*   Updated: 2022/01/28 23:13:58 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "structs.h"

/*ERROR HANDLING FUNCTIONS*/
int		ft_isnum(char *s);
int		check_ione(char *av);
int		check_itwo(int ac, char **av);
int		check_input(int ac, char **av);
void	print_errors(int error_code);

/*QUICK SORT*/
int		partition(int **arr, int low, int high);
void	swap(int *a, int *b);
void	quicksort(int **arr, int low, int high);

/*Rotating The Stacks*/
void	rotate_stack(int **stack);
void	rev_rotate_stack(int **stack);
void	rotate_both(int **stack, int **stack2);
void	rev_rotate_both(int **stack, int **stack2);

/*Pushing The Stacks*/
void	push_stack(int **stack, int **stack2);

/*Swapping The Stacks*/
void	swap_stack(int **stack);
void	swap_both(int **stack, int **stack2);

/*MAIN PUSHSWAP ALGO*/
void	push_swap(char ***stack, int size);
void	check_smaller(int size);

/*UTILITIES*/
int		count_elems(int *stack);
int		*split_atoi(char **list, int elems);

/*DO OPERATION*/
void	do_op(int op);
void	do_op_2(int op);
void	do_op_3(int op);

#endif
