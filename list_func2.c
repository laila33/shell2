#include "shell_.h"

/**
 * len_l - define length of linked list.
 *
 * @h: pointer to first node
 *
 * Return: length of list
 */
size_t len_l(const my_list_t *h)
{
	size_t j = 0;

	while (h)
	{
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * strings_l - returns  array of strings of the list->s.
 *
 * @h: pointer to first node.
 *
 * Return: array of strings.
 */
char **strings_l(my_list_t *h)
{
	my_list_t *c_node = h;
	size_t x = len_l(h), y;
	char **ss;
	char *s;

	if (!h || !x)
		return (NULL);
ss = malloc(sizeof(char *) * (x + 1));
	if (!ss)
	return (NULL);
	for (x = 0; c_node; c_node = c_node->next, x++)
	{
	s = malloc(strlen_func(c_node->s) + 1);
	if (!s)
		{
		for (y = 0; y < x; y++)
			free(ss[y]);
		free(ss);
		return (NULL);
		}

	s = strcpy_func(s, c_node->s);
	ss[x] = str;
	}
ss[x] = NULL;
return (ss);
}

/**
 * nodes_index - find index of  node.
 *
 * @h: pointer to list first node.
 *
 * @c_node: pointer to the node.
 *
 * Return: index of node or -1.
 */
ssize_t nodes_index(my_list_t *h,my_list_t *c_node)
{
	size_t j = 0;

	while (h)
	{
	if (h == c_node)
		return (j);
	h = h->next;
	j++;
	}
return (-1);
}


/**
 * start_with - returns node whose string starts with prefix.
 *
 * @c_node: pointer to list head.
 * @prefix: string to match.
 * @ch: the next character after prefix.
 *
 * Return: match node or null
 */
my_list_t *start_with(my_list_t *c_node, char *prefix, char ch)
{
	char *x = NULL;

	while (c_node)
	{
	x = start_with_func(c_node->s, prefix);
	if (x && ((ch == -1) || (*x == ch)))
		return (c_node);
	c_node = c_node->next;
	}
	return (NULL);
}



/**
 * print_l - print elements of my_list_t.
 *
 * @h: pointer to first node.
 *
 * Return: length of list
 */
size_t print_l(const my_list_t *h)
{
	size_t x = 0;

	while (h)
	{
	puts_func(convert_3(h->number, 10, 0));
	_putchar(':');
	putchar_func(' ');
	puts_func(h->s ? h->s : "(nil)");
	puts_func("\n");
	h = h->next;
	x++;
	}
return (x);
}

