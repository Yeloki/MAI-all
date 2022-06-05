#include <stdio.h>
#include "iter.h"

void l_init(list *l)
{
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
}

void l_destroy(list *l)
{
	list_el *el = l->first;
	list_el *next_el;
	while (el != NULL)
	{
		next_el = el->next;
		free(el);
		el = next_el;
	}
	l->size = 0;
	l->first = NULL;
	l->last = NULL;
}

bool is_empty(list *l) {
	return l->size == 0;
}

int l_pop_front(list *l) {
	iter begin = iter_begin(l);
	if (l->first == NULL) {
		printf("spisok pust");
	}
	int res = iter_remove(&begin);
	return res;
}

bool l_push_front(list *l, int val) {
	iter begin = iter_begin(l);
	if (!iter_insert_before(&begin, val)) {
		return false;
	}
	return true;
}

 bool l_push_back(list *l, int val) {
	iter rend = iter_rend(l);
	if (!iter_insert_before(&rend, val)) {
		return false;
	}
	
	return true;
} 

int l_pop_back(list *l) {
	iter end = iter_end(l);
	if (l->first == NULL) {
		printf("spisok pust");
	}
	int res = iter_remove(&end);
	return res;
} 

void l_print(list *l)
{
	if (l->first == NULL)
	{
		printf("Spisok pust!\n");
		return;
	}

	iter rend = iter_rend(l);
	for (iter begin = iter_begin(l); !iter_equals(begin, rend); iter_move_next(&begin)) {
		printf("%d ", iter_get_value(begin));
	}
	printf("\n");
}

