#include "shell_.h"

/**
 * add_new_node - add  node at the start of linked list.
 *
 * @head: address of pointer to head node.
 *
 * @str: s field of node.
 *
 * @number: node index.
 *
 * Return: length of list.
 */
my_list_t *add_new_node(my_list_t **head, const char *str, int number)
{
	my_list_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(my_list_t));
	if (!new)
		return (NULL);
	memset_func((void *)new, 0, sizeof(my_list_t));
	new->number = number;
	if (str)
	{
		new->str = strdup_func(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *head;
	*head = new;
	return (new);
}



/**
 * add_end_node - add new  node at the end of the linked list.
 *
 * @head: address of pointer to head node.
 *
 * @str: str field of node.
 *
 * @number: node index.
 *
 * Return: size of list
 */
my_list_t *add_end_node(my_list_t **head, const char *str, int number)
{
	my_list_t *new, *end_node;

	if (!head)
		return (NULL);

	end_node = *head;
	new = malloc(sizeof(my_list_t));
	if (!new)
		return (NULL);
	memset_func((void *)new, 0, sizeof(my_list_t));
	new->number = number;
	if (str)
	{
		new->str = strdup_func(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	if (end_node)
	{
		while (end_node)
			end_node = end_node->next;
		end_node->next = new;
	}
	else
		*head = new;
	return (new);
}


/**
 * print_str - print str element of  linked list.
 *
 * @p: pointer to first node
 *
 * Return: length of list.
 */
size_t print_str(const my_list_t *p)
{
	size_t j = 0;

	while (p)
	{
		puts_func(p->str ? p->str : "(nil)");
		puts_func("\n");
		p = p->next;
		j++;
	}
	return (j);
}




/**
 * freee_func - free all nodes.
 *
 * @ptr: pointer address of head node.
 *
 * Return: void
 */
void freee_func(my_list_t **ptr)
{
	my_list_t *c_node, *next_node, *head_node;

	if (!ptr || !*ptr)
		return;
	head_node = *ptr;
	c_node = head_node;
	while (c_node)
	{
		next_node = node->next;
		free(c_node->str);
		free(c_node);
		c_node = next_node;
	}
	*ptr = NULL;
}

/**
 * remove_node - delete node at specfic index.
 *
 * @head: address of pointer to first node.
 *
 * @i: index of node.
 *
 * Return: 1 or 0.
 */



int remove_node(my_list_t **head, unsigned int i)
{
	my_list_t *c_node, *p_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!i)
	{
		c_node = *head;
		*head = (*head)->next;
		free(c_node->str);
		free(c_node);
		return (1);
	}
	C_node = *head;
	while (c_node)
	{
		if (j == i)
		{
			p_node->next = c_node->next;
			free(c_node->str);
			free(c_node);
			return (1);
		}
		j++;
		p_node = c_node;
		c_node = c_node->next;
	}
	return (0);
}
