#include "lists.h"

/**
 * insert_node - insert a node in order
 * @head: head of like list node
 * @number: number of node inserted
 * Return: listint_t*
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL;
	/*
    * insert_node:: (NULL, number) -> NULL
    */
	if (!head)
	{
		return (NULL);
	}
	/*
    * insert_node:: (*NULL, number) -> NULL
    */
	if (!*head)
	{
		node = malloc(sizeof(listint_t)), node->next = NULL, node->n = number;
		*head = node;
		return (node);
	}
	/*
    * insert_node:: (*{ n } : *NULL, number) | n > number -> *listint_t
    */
	if ((*head)->n > number)
	{
		node = malloc(sizeof(listint_t)), node->next = NULL, node->n = number;
		node->next = (*head), *head = node;
		return (node);
	}
	/*
    * insert_node:: (_: *{ n } : list, number) | n > number -> *listint_t
    */
	if ((*head)->next && (*head)->next->n > number)
	{
		node = malloc(sizeof(listint_t)), node->next = NULL, node->n = number;
		node->next = (*head)->next, (*head)->next = node;
		return (node);
	}
	/*
    * insert_node:: (_ : [*listint_t], number)
	*               -> insert_node(listint_t, number)
    */
	return (insert_node(&((*head)->next), number));
}
