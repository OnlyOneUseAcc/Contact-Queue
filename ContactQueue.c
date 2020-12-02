#include "ContactQueue.h"
#include <stdlib.h>
#include <stdio.h>

struct ContactQueue queueConstructor() {
	struct ContactQueue result;
	result.count = 0;
	result.head = NULL;
	result.head = malloc(sizeof(result.head));
	return result;
}

void enqueue(struct ContactQueue* storage, struct Contact* vector) {
	struct Node* node = malloc(sizeof(struct Node));
	node->value = vector;
	node->next = storage->head;
	storage->head = node;
	storage->count++;

}

void print(struct ContactQueue* storage) {
	if (storage->count > 0) {
		struct Node* curEl = storage->head;
		for (int i = 0; i < storage->count; i++) {
			printf("\t%d: %s - %s\n", storage->count - i, curEl->value->name, curEl->value->phone);
			curEl = curEl->next;
		}
	}
}

struct Contact* dequeue(struct ContactQueue* storage) {
	if (storage->count == 0) {
		return NULL;
	}

	struct Node* result;

	if (storage->count == 1) {
		result = storage->head;
		storage->head = NULL;
		storage->count--;
	}
	else {

		struct Node* curElement = storage->head;
		for (int i = 0; i < storage->count - 2; i++) {
			curElement = curElement->next;
		}
		result = curElement->next;
		curElement->next = NULL;
		storage->count--;
		
	}
	return result->value;
}