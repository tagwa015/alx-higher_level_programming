#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome recursively
 * @head: double pointer to the head of the list
 * Return: 0 if not a palindrome, 1 if a palindrome
 */
int is_palindrome(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return (1);
    
    return (aux_palind(head, *head));
}

/**
 * aux_palind - auxiliary function to check if a linked list is a palindrome
 * @start: start node of the list
 * @end: end node of the list
 * Return: 0 if not a palindrome, 1 if a palindrome
 */
int aux_palind(listint_t *head, listint_t *end)
{
    if (end == NULL)
        return (1);
    
    if (aux_palind(start, end->next) && (*head)->n == end->n)
    {
        *head = (*head)->next;
        return (1);
    }

    return (0);
}
