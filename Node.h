#ifndef NODE
#define NODE

#include "Contact.h"

struct Node {
	struct Contact* value;
	struct Node* next;
};

struct Node nodeConstructor(struct Contact* value);

#endif