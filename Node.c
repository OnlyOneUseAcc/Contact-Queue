#include "Node.h"
#include <stdlib.h>

struct Node nodeConstructor(struct Contact* value) {
	struct Node result;
	result.value = value;
	result.next = NULL;
	result.next = malloc(sizeof(result.next));
	return result;

}