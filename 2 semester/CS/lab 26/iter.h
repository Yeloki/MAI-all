#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

typedef struct
{
	list *l;
	list_el **pos;
} iter; 

iter iter_begin(list *l); // привязан к first
iter iter_end(list *l); // привязан к last
iter iter_rend(list *l); // одноразовый, остаётся на месте last->next 
bool iter_equals(iter a, iter b);
void iter_move_next(iter *it);
int iter_get_value(iter it);
void iter_set_value(iter it, int val);
bool iter_insert_before(iter *it, int val); // О(n), если мы отправляем iter_end
int iter_remove(iter *it); // при удалении последнего элемента - O(n)

