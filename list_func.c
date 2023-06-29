#include "shell.h"

my_list_t *insert_node(my_list_t **top, const char *s, int number);
my_list_t *insert_end_node(my_list_t **top, const char *s, int number);
size_t print_node(const my_list_t *top);
int delete_index(my_list_t **h, unsigned int i);
void free_linked(my_list_t **top_ptr);



/**
 * insert_node - add node to the start of the linked list.
 * @top: address of pointer to first node
 * @s: s Field of  the node.
 * @number: node index used by history
 *
 * Return: LENGTH  of list.
 */
my_list_t *insert_node(my_list_t **top, const char *s, int number)
{
	my_list_t *new;

	if (!top)
		return (NULL);
	new = malloc(sizeof(my_list_t));
	if (!new)
		return (NULL);
	memset_func((void *)new, 0, sizeof(my_list_t));
	new->number = number;
	if (s)
	{
		new->s = strdup_func1(s);
		if (!new->s)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *top;
	*top = new;
	return (new);
}

/**
 * insert_end_node- insert node to the end of linked list
 * @top: Address of pointer to TOP node
 * @s: S Field node
 * @number: node index used by history
 *
 * Return: size of list
 */
my_list_t *insert_end_node(my_list_t **top, const char *s, int number)
{
	my_list_t *new, *node;

	if (!top)
		return (NULL);

	node = *top;
	new = malloc(sizeof(my_list_t));
	if (!new)
		return (NULL);
	memset_func((void *)node, 0, sizeof(my_list_t));
	new->number = number;
	if (s)
	{
		new->s = strdup_func1(s);
		if (!new->s)
		{
			free(new);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*top = new;
	return (new);
}

/**
 * print_node - print only the s element of mr_list_t  list.
 * @top: pointer to top node
 *
 * Return: length of list
 */
size_t print_node(const my_list_t *top)
{
	size_t j = 0;

	while (top)
	{
		puts_func(top->s ? top->s : "(nil)");
		puts_func("\n");
		top = top->next;
		j++;
	}
	return (j);
}

/**
 * delete_index - deletes node at given index
 * @h: address of pointer to first node
 * @i: Index of node to delete IT.
 *
 * Return: 1 OR 0.
 */
int delete_index(my_list_t **h, unsigned int i)
{
	my_list_t *node, *b_node;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);

	if (!i)
	{
		node = *h;
		*h = (*h)->next;
		free(node->s);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (j == i)
		{
			b_node->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		j++;
		b_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_linked - free node of a linked list
 * @top_ptr: Asddress of pointer to top c_node
 *
 * Return: (void)
 */
void free_linked(my_list_t **top_ptr)
{
	my_list_t *node, *next_node, *h;

	if (!top_ptr || !*top_ptr)
		return;
	h = *top_ptr;
	node = h;
	while (node)
	{
		next_node = node->next;
		free(node->s);
		free(node);
		node = next_node;
	}
	*top_ptr = NULL;
}
