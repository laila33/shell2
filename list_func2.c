#include "shell_.h"

/**
 * l_l - define size of list.
 * @top: pointer to head
 *
 * Return: length of list
 */
size_t l_l(const my_list_t *top)
{
	size_t j = 0;

	while (top)
	{
		top = top->next;
		j++;
	}
	return (j);
}

/**
 * l_to_s - Return arr of string of mt_list->s
 * @top: Pointer to HEAD.
 *
 * Return: Array of string.
 */
char **l_to_s(my_list_t *top)
{
	my_list_t *c_node = top;
	size_t x = l_l(top), y;
	char **ss;
	char *s;

	if (!top || !x)
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

		s = strcpy_func1(s, c_node->s);
		ss[x] = s;
	}
	ss[x] = NULL;
	return (ss);
}


/**
 * put_liststr - print element of a my_list_ list.
 * @top: Pointer to HEAD node
 *
 * Return: LENGTH of list
 */
size_t put_liststr(const my_list_t *top)
{
	size_t x = 0;

	while (top)
	{
		puts_func(top->s ? top->s : "(nil)");
		puts_func("\n");
		top = top->next;
		x++;
	}
	return (x);
}

/**
 * start_node - Return node it's string start with x.
 * @c_node: pointer to top of list
 * @x: string to USE
 * @ch: the next char after x to match
 *
 * Return: MatchED node , null
 */
my_list_t *start_node(my_list_t *c_node, char *x, char ch)
{
	char *a = NULL;

	while (c_node)
	{
		a = starts_with_func(c_node->s, x);
		if (a && ((ch == -1) || (*a == ch)))
			return (c_node);
		c_node = c_node->next;
	}
	return (NULL);
}

/**
 * find_node_index - find index of node
 * @top: pointer to head
 * @c_node: pointer to tany node
 *
 * Return: Index of node , -1.
 */
ssize_t find_node_index(my_list_t *top, my_list_t *c_node)
{
	size_t j = 0;

	while (top)
	{
		if (top == c_node)
			return (j);
		top = top->next;
		j++;
	}
	return (-1);
}
