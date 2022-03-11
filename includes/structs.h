/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 05:43:33 by kamin             #+#    #+#             */
/*   Updated: 2022/03/12 01:11:45 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


typedef struct s_stack
{
	struct s_node	*head;
	int				elems;
}		t_bp;

struct s_node {
	int data;
	struct s_node* next;
	struct s_node* prev;
}		t_node;

struct s_stacks
{
	t_bp	a;
	t_bp	b;
	t_bp	s;
	int		mp;
	int		*chunks;
	int		chunks_s;
}		t_stack;
#endif
