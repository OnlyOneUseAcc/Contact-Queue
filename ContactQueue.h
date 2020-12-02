#ifndef VECTOR_QUEUE
#define VECTOR_QUEUE

#include "Node.h"

struct ContactQueue {

	int count;
	struct Node* head;

};

struct ContactQueue queueConstructor();
struct Contact* dequeue(struct ContactQueue* storage);
void enqueue(struct ContactQueue* storage, struct Contact* vector);
void print(struct ContactQueue* storage);

#endif