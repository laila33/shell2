#include "shell_.h"
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
	my_list_t *new, *c_node;

	if (!top)
		return (NULL);

	c_node = *top;
	new = malloc(sizeof(my_list_t));
	if (!new)
		return (NULL);
	memset_func((void *)c_node, 0, sizeof(my_list_t));
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
	if (c_node)
	{
		while (c_node->next)
			c_node = c_node->next;
		c_node->next = new;
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
	my_list_t *c_node, *b_node;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);

	if (!i)
	{
		c_node = *h;
		*h = (*h)->next;
		free(c_node->s);
		free(c_node);
		return (1);
	}
	c_node = *h;
	while (c_node)
	{
		if (j == i)
		{
			b_node->next = c_node->next;
			free(c_node->s);
			free(c_node);
			return (1);
		}
		j++;
		b_node = c_node;
		c_node = c_node->next;
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
	my_list_t *c_node, *next_node, *h;

	if (!top_ptr || !*top_ptr)
		return;
	h = *top_ptr;
	c_node = h;
	while (c_node)
	{
		next_node = c_node->next;
		free(c_node->s);
		free(c_node);
		c_node = next_node;
	}
	*top_ptr = NULL;
}
