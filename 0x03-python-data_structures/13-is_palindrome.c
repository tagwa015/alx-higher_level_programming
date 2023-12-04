#!/usr/bin/python3
#include <stdio.h>
#include <stdlib.h>

/**
 * struct ListNode - List node structure
 * @val: Value of the node
 * @next: Pointer to the next node
 */
typedef struct ListNode
{
	int val;
	struct ListNode *next;
} listint_t;

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}

	if (fast != NULL)
		slow = slow->next;

	while (prev != NULL && slow != NULL)
	{
		if (prev->val != slow->val)
			return (0);

		prev = prev->next;
		slow = slow->next;
	}

	return (1);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *head = NULL;
	listint_t *second = NULL;
	listint_t *third = NULL;
	listint_t *fourth = NULL;

	head = malloc(sizeof(listint_t));
	second = malloc(sizeof(listint_t));
	third = malloc(sizeof(listint_t));
	fourth = malloc(sizeof(listint_t));

	head->val = 1;
	second->val = 2;
	third->val = 2;
	fourth->val = 1;

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;

	int result = is_palindrome(&head);
	printf("%d\n", result);

	free(head);
	free(second);
	free(third);
	free(fourth);

	return (0);
}
