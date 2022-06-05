#include <stdio.h>

#include "iter.h"

int remove_max(list *l) {
	iter MAX;
	int max= -2147483648;
	iter rend = iter_rend(l);
	for(iter begin = iter_begin(l); !iter_equals(begin, rend); iter_move_next(&begin)) {
		if (iter_get_value(begin) > max) {
			max=iter_get_value(begin);
			MAX=begin;
		}
	}
	int res=iter_remove(&MAX);
	return res;
}

void sort(list *l) {
	list l_tmp;
	l_init(&l_tmp);
	int res;
	while(!is_empty(l)) {
		res=remove_max(l);
		l_push_back(&l_tmp, res);
	}
	while(!is_empty(&l_tmp)) {
		res=l_pop_front(&l_tmp);
		l_push_front(l, res);
	}
}
