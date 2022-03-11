/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:25:25 by kamin             #+#    #+#             */
/*   Updated: 2022/03/12 02:26:21 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	add_dll_front(struct s_node** head, int new_data)
{
	struct s_node*	new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));
	new_node->data = new_data;
	new_node->next = (*head);
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
}

void	add_dll_back(struct s_node** head, int new_data)
{
	struct s_node* new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));
	struct s_node* last = *head;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head == NULL) {
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	/* pretty much check if u need this or not*/
	return;
}

void	deleteNode(struct s_node** head, int key)
{
	// Store head node
	struct s_node *tmp;
	struct s_node *prev;
	
	 tmp = *head;
	// If head node itself holds the key to be deleted
	if (tmp != NULL && tmp->data == key) {
		*head = tmp->next; // Changed head
		free(tmp); // free old head
		if ((*head))
			(*head)->prev = NULL;
	}
	else
	{
		while (tmp != NULL && tmp->data != key) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp != NULL)
		{
			prev->next = tmp->next;
			free(tmp);
		}
	}
}

void	printList(struct s_node* node)
{
	struct s_node* last;
	while (node != NULL) {
		printf("%d ", node->data);
		last = node;
		node = node->next;
	}
}

void	reset_stack(t_bp *stack)
{
	if ((*stack).head)
	{
		while ((*stack).head->prev != NULL)
			(*stack).head = (*stack).head->prev;
	}
}

void	stack_last(t_bp *stack)
{
	if ((*stack).head)
	{
		while ((*stack).head->next != NULL)
			(*stack).head = (*stack).head->next;
	}
}
