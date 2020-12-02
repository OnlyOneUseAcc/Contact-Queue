#include "Contact.h"

struct Contact contactConstructor(char name[30], char phone[30]) {
	struct Contact result;
	for (int i = 0; i < 30; i++) {
		result.name[i] = name[i];
		result.phone[i] = phone[i];
	}
	return result;
}
