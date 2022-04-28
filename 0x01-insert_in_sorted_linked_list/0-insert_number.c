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
  listint_t *newNode = NULL;
  if (head == NULL)
  {
    return (NULL); 
  }
  node = *head;
  newNode = malloc(sizeof(listint_t));
  if (newNode == NULL)
  {
    return NULL;
  }
  newNode->n = number;
  if (!node || node->n > number)
  {

    newNode->next = *head;
    *head = newNode;
  } else
  {
    while(node->next->n < number && node->next != NULL)
      {
        node = node->next;
      }
    newNode->n = number;
    newNode->next = node->next;
    node->next = newNode;
  }

  return(newNode);
}
