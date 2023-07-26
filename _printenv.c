#include "main.h"

/**
 * _printenv - prints all environment variables in linked list
 * Description: prints the env variables
 *
 * @head: pointer to start of the list
 *
 * Return: void
 */
void _printenv(enode *head)
{
	enode *current_node = head;

	if (current_node == NULL)
		return;

	while (current_node)
	{
		_puts(current_node->name);
		_puts("=");
		_puts(current_node->value);
		_puts("\n");
		current_node = current_node->next_node;
	}
}
