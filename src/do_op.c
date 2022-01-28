/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:12:14 by kamin             #+#    #+#             */
/*   Updated: 2022/01/28 23:13:00 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_op(int op)
{
	if (op == 0)
	{
		push_stack(&t_stack.a, &t_stack.b);
		write(1, "pb\n", 3);
	}
	else if (op == 1)
	{
		push_stack(&t_stack.b, &t_stack.a);
		write(1, "pa\n", 3);
	}
	else if (op == 2)
	{
		rotate_stack(&t_stack.a);
		write(1, "ra\n", 3);
	}
	else if (op == 3)
	{
		rotate_stack(&t_stack.b);
		write(1, "rb\n", 3);
	}
	else if (op > 3)
		do_op_2(op);
}

void	do_op_2(int op)
{
	if (op == 4)
	{
		rotate_both(&t_stack.a, &t_stack.b);
		write(1, "rr\n", 3);
	}
	else if (op == 5)
	{
		rev_rotate_stack(&t_stack.a);
		write(1, "rra\n", 4);
	}
	else if (op == 6)
	{
		rev_rotate_stack(&t_stack.b);
		write(1, "rrb\n", 4);
	}
	else if (op == 7)
	{
		rev_rotate_both(&t_stack.a, &t_stack.b);
		write(1, "rrr\n", 4);
	}
	else if (op > 7)
		do_op_3(op);
}

void	do_op_3(int op)
{
	if (op == 8)
	{
		swap_stack(&t_stack.a);
		write(1, "sa\n", 3);
	}
	else if (op == 9)
	{
		swap_stack(&t_stack.b);
		write(1, "sb\n", 3);
	}
	else if (op == 10)
	{
		swap_both(&t_stack.a, &t_stack.b);
		write(1, "ss\n", 3);
	}
}
