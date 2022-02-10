/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:25:25 by kamin             #+#    #+#             */
/*   Updated: 2022/02/11 00:06:01 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
void push(struct s_node** head_ref, int new_data)
{
	struct s_node*	new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
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
void add_dll_back(struct s_node** head_ref, int new_data)
{
	struct s_node* new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));
	struct s_node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	/* pretty much check if u need this or not*/
	return;
}

// This function prints contents of linked list starting
// from the given node
void printList(struct s_node* node)
{
	struct s_node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf("%d", node->data);
		last = node;
		node = node->next;
	}
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
