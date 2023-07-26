#include "main.h"

/**
 * strargs_tolist - converts an array of string arguments to linked list
 * Description: receives an array of environment variables and converts
 * it to a singly linked list, with a single node for each variable
 *
 * @args: array of environment variables
 *
 * Return: pointer to head of linked list
 */
enode *strargs_tolist(char **args)
{
	int i, j, len_args;
	char *name = NULL, *value = NULL;
	enode *head = NULL;

	if (args == NULL)
		return (NULL);

	for (len_args = 0; args[len_args] != NULL; len_args++)
	{
		for (i = 0; args[len_args][i] != '\0'; i++)
		{
			if (args[len_args][i] == '=')
				break;
		}
		name = malloc(sizeof(char) * (i + 1));
		value = malloc(sizeof(char) * (_strlen(args[len_args]) - i));
/* refactor to check name and value above for successful allocation*/
		for (j = 0; j < i; j++)
		{
			name[j] = args[len_args][j];
		}
		name[j] = '\0';
		i++;
		for (j = 0; args[len_args][i] != '\0'; j++, i++)
		{
			value[j] = args[len_args][i];
		}
		value[j] = args[len_args][i];
		if (head == NULL)
			head = add_node_end(head, name, value);
		else
			add_node_end(head, name, value);
		free(name);
		free(value);
		name = NULL;
		value = NULL;
	}
	return (head);
}

/**
 * add_node_end - adds a node to the end of a linked list
 * Description: takes a pointer to the head of an env variables
 * linked list, along with a variable name and variable value
 * creates a node and adds it to the end of the env variables
 * linked list
 *
 * @head: pointer to first node in the list
 * @vname: string variable name
 * @vvalue: string variable value
 *
 * Return: pointer to node added to linked list
 */
enode *add_node_end(enode *head, char *vname, char *vvalue)
{
	enode *current_node = head, *new_node;

	new_node = malloc(sizeof(enode));
	if (new_node == NULL) /* check vname, vvalue, return null if null*/
		return (NULL);
	new_node->name = _strdup(vname);
	new_node->value = _strdup(vvalue);
	new_node->next_node = NULL;

	if (current_node == NULL)
	{
		current_node = new_node;
		head = new_node;
		return (new_node);
	}

	while (current_node->next_node)
		current_node = current_node->next_node;
	current_node->next_node = new_node;
	return (new_node);
}

/**
 * free_list - frees singly linked list of env variables
 * Description: receives a pointer to a head node of a list
 * and frees the memory allocated for all the nodes in the list
 *
 * @head: pointer to first node in linked list
 *
 * Return: void
 */
void free_list(enode **head)
{
	enode *current_node = *head, *temp;

	if (current_node == NULL)
		return;

	while (current_node)
	{
		temp = current_node->next_node;
		free(current_node->name);
		free(current_node->value);
		free(current_node);
		current_node = NULL;
		current_node = temp;
	}
	*head = NULL;
}

/**
 * delete_node - deletes a node from the env linked list
 * Description: takes a pointer to the start of a list and an env
 * variable name and deletes the first matching node it finds
 * within the list
 *
 * @head: pointer to head node in linked list structure
 * @vname: variable name to delete from list
 *
 * Return: -1 if error, 0 otherwise
 */
int delete_node(enode **head, char *vname)
{
	enode *current_node = *head, *temp = NULL;
	int pos = 0, _match = 0;

	if (current_node == NULL)
	{
		return (-1);
	}

	while (current_node)
	{
		if (_strcmp(vname, current_node->name) == 0)
		{
			_match = 1;
			break;
		}
		pos++;
		temp = current_node;
		current_node = current_node->next_node;
	}
	if (_match == 0)
		return (0);
	if (pos == 0)
	{
		temp = *head;
		*head = current_node->next_node;
		free(temp->name);
		free(temp->value);
		free(temp);
		temp = NULL;
		return (0);
	}
	temp->next_node = current_node->next_node;
	free(current_node->name);
	free(current_node->value);
	free(current_node);
	current_node = NULL;
	return (0);
}

/**
 * _size_envlist - returns number of environment variables in linked list
 * Description: total number of variables in environment
 *
 * @head: pointer to start of the list
 *
 * Return: void
 */
int _size_envlist(enode *head)
{
	enode *current_node = head;
	int _len = 0;

	while (current_node)
	{
		_len++;
		current_node = current_node->next_node;
	}
	return (_len);
}
