#include <stdio.h>
#include "sort.h"

int main()
{
	int value;
	list l;
	l_init(&l);
	while (scanf("%d", &value) == 1) {
		l_push_back(&l, value);
	}
	sort(&l);
	l_print(&l);

	return 0;
}
