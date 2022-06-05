#include <stdio.h>
#include "iter.h"

iter iter_begin(list *l)
{
	iter it;
	it.pos = &(l->first);
	it.l = l;
	return it;
}

iter iter_end(list *l)
{
	iter it;
	it.pos = &(l->last);
	it.l = l;
	return it;
}

iter iter_rend(list *l)
{
	iter it;
	if (l->last == NULL)
	{
		it.pos = &(l->first);
	}
	else
	{
		it.pos = &(l->last->next);
	}
	it.l = l;
	return it;
}

bool iter_equals(iter a, iter b)
{
	return (a.pos == b.pos && a.l == b.l);
}

void iter_move_next(iter *it)
{
	it->pos = &((*it->pos)->next);
}

int iter_get_value(iter it)
{
	list_el **pos = it.pos;
	return (*pos)->val;
}

void iter_set_value(iter it, int val)
{
	(*it.pos)->val = val;
}

bool iter_insert_before(iter *it, int val)
{
	list_el **iter = it->pos;
	list *l = it->l;

	list_el *new_node = (list_el *)malloc(sizeof(list_el));
	if (new_node == NULL)
	{
		return false;
	}

	new_node->val = val;
	new_node->next = *iter;

	if (l->first == NULL || *iter == NULL)
	{
		l->last = new_node;
	}
	else if (*iter == l->last && iter == &(l->last))
	{
		list_el **pos = &(l->first);
		while ((*pos)->next != NULL)
		{
			pos = &((*pos)->next);
		}
		*pos = new_node;
		l->size++;
		return true;
	}

	*iter = new_node;
	l->size++;
	return true;
}

int iter_remove(iter *it)
{
	list_el **iter = it->pos;
	list *l = it->l;
	list_el *tofree = *iter;
	int res = (*iter)->val;

	if (*iter == NULL)
	{
		printf("double pointer to NULL\n");
	}

	if (*iter == l->last)
	{
		if (l->first == l->last)
		{
			l->last = NULL;
			l->first = NULL;
			free(tofree);
			l->size--;
			return res;
		}

		list_el **pos = &(l->first);
		while ((*pos)->next->next != NULL)
		{
			pos = &((*pos)->next);
		}
		(*pos)->next = NULL;
		l->last = *pos;
		l->size--;
		free(tofree);
		return res;
	}
	*iter = ((*iter)->next);
	free(tofree);
	l->size--;
	return res;
}

