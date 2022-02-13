/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:25:25 by kamin             #+#    #+#             */
/*   Updated: 2022/02/13 19:24:13 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
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

/* Given a node as prev_node, insert a new node after the
* given node */
void insertAfter(struct s_node* prev_node, int new_data)
{
	struct s_node* new_node;
	if (prev_node != NULL)
	{
		new_node = (struct s_node*)malloc(sizeof(struct s_node));
		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
		new_node->prev = prev_node;
		if (new_node->next != NULL)
			new_node->next->prev = new_node;
	}
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void add_dll_back(struct s_node** head, int new_data)
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

// This function prints contents of linked list starting
// from the given node
void printList(struct s_node* node)
{
	struct s_node* last;
	while (node != NULL) {
		printf("%d ", node->data);
		last = node;
		node = node->next;
	}
}

void reset_stack(t_bp *stack)
{
	while ((*stack).head->prev != NULL)
		(*stack).head = (*stack).head->prev;
}

void stack_last(t_bp *stack)
{
	while ((*stack).head->next != NULL)
		(*stack).head = (*stack).head->next;
}

// /* Driver program to test above functions*/
// int main()
// {
// 	/* Start with the empty list */
// 	struct s_node* head = NULL;

// 	// Insert 6. So linked list becomes 6->NULL
// 	append(&head, 6);

// 	// Insert 7 at the beginning. So linked list becomes
// 	// 7->6->NULL
// 	push(&head, 7);

// 	// Insert 1 at the beginning. So linked list becomes
// 	// 1->7->6->NULL
// 	push(&head, 1);

// 	// Insert 4 at the end. So linked list becomes
// 	// 1->7->6->4->NULL
// 	append(&head, 4);

// 	// Insert 8, after 7. So linked list becomes
// 	// 1->7->8->6->4->NULL
// 	insertAfter(head->next, 8);

// 	printf("Created DLL is: ");
// 	printList(head);

// 	getchar();
// 	return 0;
// }
